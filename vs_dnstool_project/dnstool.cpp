#include <bits/stdc++.h>

#if defined(_WIN32) || defined(_WIN64)
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include <windows.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
using socklen_t = int;
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#endif

using namespace std;

static void platform_sleep_ms(int ms) {
#if defined(_WIN32) || defined(_WIN64)
	Sleep(ms);
#else
	this_thread::sleep_for(chrono::milliseconds(ms));
#endif
}

static void close_socket(int s) {
#if defined(_WIN32) || defined(_WIN64)
	closesocket(s);
#else
	close(s);
#endif
}

static bool init_sockets() {
#if defined(_WIN32) || defined(_WIN64)
	WSADATA wsaData;
	return WSAStartup(MAKEWORD(2,2), &wsaData) == 0;
#else
	return true;
#endif
}

static void cleanup_sockets() {
#if defined(_WIN32) || defined(_WIN64)
	WSACleanup();
#endif
}

static string get_exe_dir(char** argv) {
#if defined(_WIN32) || defined(_WIN64)
	char modpath[MAX_PATH];
	if (GetModuleFileNameA(NULL, modpath, MAX_PATH) > 0) {
		string mp = modpath; size_t p = mp.find_last_of("\\/");
		if (p != string::npos) return mp.substr(0,p+1);
	}
	return string();
#else
	if (argv && argv[0]) {
		string mp = argv[0]; size_t p = mp.find_last_of("/\\");
		if (p != string::npos) return mp.substr(0,p+1);
	}
	return string();
#endif
}

static string join_vec(const vector<string>& v, const string &sep=","){
	string s;
	for(size_t i=0;i<v.size();++i){ if(i) s+=sep; s+=v[i]; }
	return s;
}

static void save_config(const string &dir, const vector<string>& domains, const vector<string>& servers, int probes, int timeout_ms, bool include_ipv6) {
	string path = dir.empty()?"dnstool.conf": dir + "dnstool.conf";
	ofstream f(path);
	if(!f) return;
	f << "domains=" << join_vec(domains) << "\n";
	f << "servers=" << join_vec(servers) << "\n";
	f << "probes=" << probes << "\n";
	f << "timeout_ms=" << timeout_ms << "\n";
	f << "include_ipv6=" << (include_ipv6?"1":"0") << "\n";
}

static void load_config(const string &dir, vector<string>& domains, vector<string>& servers, int &probes, int &timeout_ms, bool &include_ipv6) {
	string path = dir.empty()?"dnstool.conf": dir + "dnstool.conf";
	ifstream f(path);
	if(!f) return;
	string line;
	while(getline(f,line)){
		size_t eq = line.find('='); if(eq==string::npos) continue;
		string k = line.substr(0,eq); string v = line.substr(eq+1);
		if(k=="domains"){ domains.clear(); size_t p=0; while(p<v.size()){ size_t q=v.find(',',p); if(q==string::npos) q=v.size(); string t=v.substr(p,q-p); if(!t.empty()) domains.push_back(t); p=q+1; } }
		else if(k=="servers"){ servers.clear(); size_t p=0; while(p<v.size()){ size_t q=v.find(',',p); if(q==string::npos) q=v.size(); string t=v.substr(p,q-p); if(!t.empty()) servers.push_back(t); p=q+1; } }
		else if(k=="probes"){ try{ probes = stoi(v);}catch(...){} }
		else if(k=="timeout_ms"){ try{ timeout_ms = stoi(v);}catch(...){} }
		else if(k=="include_ipv6"){ include_ipv6 = (v=="1"); }
	}
}

vector<uint8_t> build_dns_query(const string &hostname, uint16_t id) {
	vector<uint8_t> buf;
	buf.resize(12);
	// Header
	buf[0] = (id >> 8) & 0xFF;
	buf[1] = id & 0xFF;
	buf[2] = 0x01; // recursion desired
	buf[3] = 0x00;
	buf[4] = 0x00; buf[5] = 0x01; // QDCOUNT = 1
	buf[6] = 0x00; buf[7] = 0x00; // ANCOUNT
	buf[8] = 0x00; buf[9] = 0x00; // NSCOUNT
	buf[10] = 0x00; buf[11] = 0x00; // ARCOUNT

	// Question
	string host = hostname;
	if(host.back() != '.') host.push_back('.');
	size_t pos = 0;
	while(pos < host.size()) {
		size_t next = host.find('.', pos);
		if(next == string::npos) break;
		size_t len = next - pos;
		buf.push_back((uint8_t)len);
		for(size_t i = 0; i < len; ++i) buf.push_back((uint8_t)host[pos + i]);
		pos = next + 1;
	}
	buf.push_back(0x00); // end of name
	buf.push_back(0x00); buf.push_back(0x01); // Type A
	buf.push_back(0x00); buf.push_back(0x01); // Class IN
	return buf;
}

vector<string> get_system_dns_servers() {
	vector<string> res;
#if defined(_WIN32) || defined(_WIN64)
	ULONG flags = GAA_FLAG_SKIP_ANYCAST | GAA_FLAG_SKIP_MULTICAST | GAA_FLAG_SKIP_UNICAST;
	ULONG family = AF_UNSPEC;
	ULONG outBufLen = 15000;
	PIP_ADAPTER_ADDRESSES addresses = (PIP_ADAPTER_ADDRESSES)malloc(outBufLen);
	if (!addresses) return res;
	DWORD rv = GetAdaptersAddresses(family, flags, NULL, addresses, &outBufLen);
	if (rv == ERROR_BUFFER_OVERFLOW) {
		free(addresses);
		addresses = (PIP_ADAPTER_ADDRESSES)malloc(outBufLen);
		if (!addresses) return res;
		rv = GetAdaptersAddresses(family, flags, NULL, addresses, &outBufLen);
	}
	if (rv == NO_ERROR) {
		for (PIP_ADAPTER_ADDRESSES aa = addresses; aa; aa = aa->Next) {
			for (PIP_ADAPTER_DNS_SERVER_ADDRESS dns = aa->FirstDnsServerAddress; dns; dns = dns->Next) {
				SOCKADDR *sa = dns->Address.lpSockaddr;
				char buf[INET6_ADDRSTRLEN] = {0};
				if (!sa) continue;
				if (sa->sa_family == AF_INET) {
					sockaddr_in *sin = (sockaddr_in*)sa;
					inet_ntop(AF_INET, &sin->sin_addr, buf, sizeof(buf));
					res.emplace_back(buf);
				} else if (sa->sa_family == AF_INET6) {
					sockaddr_in6 *sin6 = (sockaddr_in6*)sa;
					inet_ntop(AF_INET6, &sin6->sin6_addr, buf, sizeof(buf));
					res.emplace_back(buf);
				}
			}
		}
	}
	free(addresses);
#else
	ifstream f("/etc/resolv.conf");
	if (!f) return res;
	string line;
	while (getline(f, line)) {
		// trim
		size_t i = 0;
		while (i < line.size() && isspace((unsigned char)line[i])) ++i;
		if (i >= line.size()) continue;
		if (line.compare(i, 10, "nameserver") == 0) {
			i += 10;
			while (i < line.size() && isspace((unsigned char)line[i])) ++i;
			size_t j = i;
			while (j < line.size() && !isspace((unsigned char)line[j])) ++j;
			if (j > i) res.push_back(line.substr(i, j - i));
		}
	}
#endif
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}

// Send a single UDP DNS query to server_ip:53, return RTT in milliseconds, or negative on failure
double probe_once(const string &server_ip, const string &hostname, int timeout_ms) {
	int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock < 0) return -1.0;

	sockaddr_in serv{};
	serv.sin_family = AF_INET;
	serv.sin_port = htons(53);
	if(inet_pton(AF_INET, server_ip.c_str(), &serv.sin_addr) <= 0) {
		close_socket(sock);
		return -1.0;
	}

	// set recv timeout
	struct timeval tv;
	tv.tv_sec = timeout_ms / 1000;
	tv.tv_usec = (timeout_ms % 1000) * 1000;
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

	// build query
	static std::mt19937 rng((uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count());
	uint16_t id = (uint16_t)rng();
	auto q = build_dns_query(hostname, id);

	auto t1 = chrono::high_resolution_clock::now();
	ssize_t sent = sendto(sock, (const char*)q.data(), (int)q.size(), 0, (sockaddr*)&serv, sizeof(serv));
	if (sent < 0) { close_socket(sock); return -1.0; }

	uint8_t recvbuf[512];
	sockaddr_in from{}; socklen_t fromlen = sizeof(from);
	ssize_t recvd = recvfrom(sock, (char*)recvbuf, sizeof(recvbuf), 0, (sockaddr*)&from, &fromlen);
	auto t2 = chrono::high_resolution_clock::now();
	close_socket(sock);
	if (recvd <= 0) return -1.0;

	double ms = chrono::duration<double, milli>(t2 - t1).count();
	// minimal validation: check id
	if (recvd >= 2) {
		uint16_t rid = (uint16_t(recvbuf[0]) << 8) | uint16_t(recvbuf[1]);
		if (rid != id) return -1.0;
	}
	return ms;
}

struct Stats { int sent=0, recv=0; double min_ms=0, max_ms=0, sum_ms=0; };

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(&cout);

	if(!init_sockets()) {
		cerr << "socket init failed\n";
		return 1;
	}

#if defined(_WIN32) || defined(_WIN64)
	// set console to UTF-8 to avoid Chinese garble
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif
	setlocale(LC_ALL, "");

	int probes = 3;
	int timeout_ms = 1500;
	vector<string> servers = {"8.8.8.8","1.1.1.1","9.9.9.9","114.114.114.114","223.5.5.5"};
	vector<string> domains = {"www.example.com","www.360.cn","github.com"};
	bool include_ipv6 = false;

	// simple arg parsing
	for(int i=1;i<argc;++i){
		string a = argv[i];
		if(a=="-d" && i+1<argc){ domains.clear(); domains.push_back(argv[++i]); }
		else if(a=="-n" && i+1<argc){ probes = stoi(argv[++i]); }
		else if(a=="-t" && i+1<argc){ timeout_ms = stoi(argv[++i]); }
		else if(a=="-s" && i+1<argc){ // single server string separated by commas
			servers.clear(); string s=argv[++i]; size_t p=0; while(p<s.size()){ size_t q=s.find(',',p); if(q==string::npos) q=s.size(); servers.push_back(s.substr(p,q-p)); p=q+1; }
		}
		else if(a=="-D" && i+1<argc){ // domains comma separated
			domains.clear(); string s=argv[++i]; size_t p=0; while(p<s.size()){ size_t q=s.find(',',p); if(q==string::npos) q=s.size(); domains.push_back(s.substr(p,q-p)); p=q+1; }
		}
		else if(a=="-6") { include_ipv6 = true; }
		else if(a=="-h" || a=="--help"){ cout<<"Usage: dnstool [-d domain] [-n probes] [-t timeout_ms] [-s ip,ip,...] [ip...](servers)\n"; cleanup_sockets(); return 0; }
		else { servers.clear(); // remaining args are server IPs
			for(int j=i;j<argc;++j) servers.push_back(string(argv[j])); break; }
	}

	bool interactive = (argc == 1);
	string exe_dir = get_exe_dir(argv);
	// load default config if exists
	load_config(exe_dir, domains, servers, probes, timeout_ms, include_ipv6);

	if (interactive) {
		// improved interactive menu with per-action confirmation to return to main menu
		while (true) {
			cout << "\n=== dnstool interactive menu ===\n";
			cout << "1) Show current settings\n";
			cout << "2) Set domains (current: ";
			for(size_t i=0;i<domains.size();++i){ if(i) cout<<","; cout<<domains[i]; } cout<<")\n";
			cout << "3) Set DNS servers (current: "; for(size_t i=0;i<servers.size();++i){ if(i) cout<<","; cout<<servers[i]; } cout<<")\n";
			cout << "4) Set probes (current: "<<probes<<")\n";
			cout << "5) Set timeout ms (current: "<<timeout_ms<<")\n";
			cout << "6) Toggle include IPv6 system DNS (current: " << (include_ipv6?"Yes":"No") << ")\n";
			cout << "7) Start tests\n";
			cout << "8) Help\n";
			cout << "9) Presets\n";
			cout << "s) Save current settings as default\n";
			cout << "0) Exit\n";
			cout << "Choice: ";
			cout.flush();
			string sel; if(!getline(cin, sel)) return 0;

			if (sel.empty()) continue;

			// perform selected action; after action ask whether return to main menu
			bool backToMenu = true;
			do {
				if (sel == "1") {
					cout << "\nCurrent settings:\n";
					cout << "  Domains: "; for(size_t i=0;i<domains.size();++i){ if(i) cout<<","; cout<<domains[i]; } cout<<"\n";
					cout << "  Servers: "; for(size_t i=0;i<servers.size();++i){ if(i) cout<<","; cout<<servers[i]; } cout<<"\n";
					cout << "  Probes: "<<probes<<"  Timeout(ms): "<<timeout_ms<<"  Include IPv6 system DNS: "<<(include_ipv6?"Yes":"No")<<"\n";
				}
				else if (sel == "2"){
					cout << "Enter comma-separated domains (empty to keep current): "; cout.flush(); string line; if(!getline(cin,line)) break; if(!line.empty()){ vector<string> nd; size_t p=0; while(p<line.size()){ size_t q=line.find(',',p); if(q==string::npos) q=line.size(); string t=line.substr(p,q-p); if(!t.empty()) nd.push_back(t); p=q+1; } if(!nd.empty()) domains.swap(nd); cout<<"Domains updated.\n"; } else cout<<"Domains unchanged.\n";
				}
				else if (sel == "3"){
					cout << "Enter comma-separated DNS IP list (empty to keep current): "; cout.flush(); string line; if(!getline(cin,line)) break; if(!line.empty()){ vector<string> ns; size_t p=0; while(p<line.size()){ size_t q=line.find(',',p); if(q==string::npos) q=line.size(); string t=line.substr(p,q-p); if(!t.empty()) ns.push_back(t); p=q+1; } if(!ns.empty()) servers.swap(ns); cout<<"Servers updated.\n"; } else cout<<"Servers unchanged.\n";
				}
				else if (sel == "4"){
					cout << "Enter probes (current "<<probes<<"): "; cout.flush(); string line; if(!getline(cin,line)) break; if(!line.empty()){ try{ int v=stoi(line); if(v>0) { probes = v; cout<<"Probes updated.\n"; } else cout<<"Must be >0\n"; } catch(...) { cout<<"Invalid number\n"; } } else cout<<"Probes unchanged.\n";
				}
				else if (sel == "5"){
					cout << "Enter timeout ms (current "<<timeout_ms<<"): "; cout.flush(); string line; if(!getline(cin,line)) break; if(!line.empty()){ try{ int v=stoi(line); if(v>0) { timeout_ms = v; cout<<"Timeout updated.\n"; } else cout<<"Must be >0\n"; } catch(...) { cout<<"Invalid number\n"; } } else cout<<"Timeout unchanged.\n";
				}
				else if (sel == "6"){
					include_ipv6 = !include_ipv6; cout << "Include IPv6 system DNS now: " << (include_ipv6?"Yes":"No") << "\n";
				}
				else if (sel == "7"){
					// start tests
					break;
				}
				else if (sel == "8"){
					cout << "Help:\n  - Run directly to enter interactive menu.\n  - Command-line mode: -d domain -D domain1,domain2 -s ip,ip -n probes -t timeout -6 (include IPv6 system DNS).\n  - Output written to console and dnstool.log (executable directory).\n";
				}
				else if (sel == "9"){
					cout << "Presets:\n  1) Developers (github.com, stackoverflow.com, npmjs.com)\n  2) Entertainment (youtube.com, netflix.com, twitch.tv)\n  3) Basic (www.example.com, www.360.cn, baidu.com)\n  0) Back\n";
					cout << "Select preset: "; cout.flush(); string ps; if(!getline(cin, ps)) break; if(ps=="1"){ domains = {"github.com","stackoverflow.com","npmjs.com"}; cout<<"Preset applied.\n";} else if(ps=="2"){ domains={"youtube.com","netflix.com","twitch.tv"}; cout<<"Preset applied.\n";} else if(ps=="3"){ domains={"www.example.com","www.360.cn","baidu.com"}; cout<<"Preset applied.\n";} else cout<<"No preset applied.\n";
                    
				}
				else if (sel == "s" || sel=="S"){
					save_config(exe_dir, domains, servers, probes, timeout_ms, include_ipv6);
					cout << "Settings saved to " << (exe_dir.empty()?"./dnstool.conf": exe_dir+"dnstool.conf") << "\n";
				}
				else if (sel == "0"){
					return 0;
				}
				else {
					cout << "Invalid choice\n";
				}

				// after action (except start tests and exit), ask whether to return to main menu
				if (sel == "7") break;
				cout << "Return to main menu? (Y/n): "; cout.flush(); string ans; if(!getline(cin, ans)){ return 0; }
				if (ans.empty() || ans[0]=='Y' || ans[0]=='y') backToMenu = true; else backToMenu = false;
			} while(!backToMenu);

			if (sel == "7") break; // begin tests
			if (sel == "0") return 0;
			// otherwise loop main menu
		}
	}

	// prepend system DNS servers (filter IPv6 unless requested)
	auto sysdns = get_system_dns_servers();
	if (!sysdns.empty()) {
		unordered_set<string> exist(servers.begin(), servers.end());
		vector<string> merged;
		for (auto &s : sysdns) {
			if (s.empty()) continue;
			if (!include_ipv6 && s.find(':')!=string::npos) continue; // skip IPv6 by default
			if (!exist.count(s)) merged.push_back(s);
		}
		for (auto &s : servers) merged.push_back(s);
		servers.swap(merged);
	}

	// join domains for header
	string dj;
	for(size_t ii=0; ii<domains.size(); ++ii) { if(ii) dj += ","; dj += domains[ii]; }
	cout << "DNS Speed Test - domains=" << dj << " probes=" << probes << " timeout=" << timeout_ms << "ms\n";
	cout << left << setw(18) << "Server" << setw(10) << "Loss%" << setw(10) << "Min(ms)" << setw(10) << "Avg(ms)" << setw(10) << "Max(ms)" << "\n";
	cout << string(60,'-') << "\n";

	// helper: parse answers and measure reachability
	auto probe_and_get_ips = [&](const string &sv, const string &host, int timeout_ms, vector<string> &out_ips) -> double {
		int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (sock < 0) return -1.0;
		sockaddr_in serv{};
		serv.sin_family = AF_INET; serv.sin_port = htons(53);
		if(inet_pton(AF_INET, sv.c_str(), &serv.sin_addr) <= 0) { close_socket(sock); return -1.0; }
		struct timeval tv; tv.tv_sec = timeout_ms/1000; tv.tv_usec = (timeout_ms%1000)*1000;
		setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
		static std::mt19937 rng((uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count());
		uint16_t id = (uint16_t)rng();
		auto q = build_dns_query(host, id);
		auto t1 = chrono::high_resolution_clock::now();
		ssize_t sent = sendto(sock, (const char*)q.data(), (int)q.size(), 0, (sockaddr*)&serv, sizeof(serv));
		if (sent < 0) { close_socket(sock); return -1.0; }
		uint8_t recvbuf[2048]; sockaddr_in from{}; socklen_t fromlen = sizeof(from);
		ssize_t recvd = recvfrom(sock, (char*)recvbuf, sizeof(recvbuf), 0, (sockaddr*)&from, &fromlen);
		auto t2 = chrono::high_resolution_clock::now(); close_socket(sock);
		if (recvd <= 0) return -1.0;
		double ms = chrono::duration<double, milli>(t2 - t1).count();
		if (recvd >= 2) {
			uint16_t rid = (uint16_t(recvbuf[0]) << 8) | uint16_t(recvbuf[1]);
			if (rid != id) return -1.0;
		}
		// parse header
		if (recvd < 12) return ms;
		int qdcount = (recvbuf[4]<<8) | recvbuf[5];
		int ancount = (recvbuf[6]<<8) | recvbuf[7];
		size_t idx = 12;
		// skip questions
		for(int qi=0; qi<qdcount; ++qi) {
			// skip qname
			while(idx < (size_t)recvd) {
				uint8_t len = recvbuf[idx];
				if (len == 0) { idx++; break; }
				if ((len & 0xC0) == 0xC0) { idx += 2; break; }
				idx += 1 + len;
			}
			idx += 4; // qtype qclass
		}
		// parse answers
		for(int ai=0; ai<ancount && idx+10 < (size_t)recvd; ++ai) {
			// skip name
			if ((recvbuf[idx] & 0xC0) == 0xC0) { idx += 2; }
			else {
				while(idx < (size_t)recvd) { uint8_t len = recvbuf[idx]; if (len==0) { idx++; break; } idx += 1+len; }
			}
			if (idx + 10 > (size_t)recvd) break;
			uint16_t type = (recvbuf[idx]<<8) | recvbuf[idx+1];
			uint16_t clas = (recvbuf[idx+2]<<8) | recvbuf[idx+3];
			uint32_t ttl = (recvbuf[idx+4]<<24) | (recvbuf[idx+5]<<16) | (recvbuf[idx+6]<<8) | recvbuf[idx+7];
			uint16_t rdlen = (recvbuf[idx+8]<<8) | recvbuf[idx+9];
			idx += 10;
			if (idx + rdlen > (size_t)recvd) break;
			if (type == 1 && rdlen == 4) { // A
				char ipbuf[INET_ADDRSTRLEN]; inet_ntop(AF_INET, &recvbuf[idx], ipbuf, sizeof(ipbuf)); out_ips.emplace_back(ipbuf);
			} else if (type == 28 && rdlen == 16) { // AAAA
				char ip6[INET6_ADDRSTRLEN]; inet_ntop(AF_INET6, &recvbuf[idx], ip6, sizeof(ip6)); out_ips.emplace_back(ip6);
			}
			idx += rdlen;
		}
		// dedupe
		sort(out_ips.begin(), out_ips.end()); out_ips.erase(unique(out_ips.begin(), out_ips.end()), out_ips.end());
		return ms;
	};

	auto tcp_connect_timeout = [&](const string &ip, int port, int timeout_ms) -> bool {
		// only IPv4 here
		int s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (s < 0) return false;
#if defined(_WIN32) || defined(_WIN64)
		u_long mode = 1; ioctlsocket(s, FIONBIO, &mode);
#else
		int flags = fcntl(s, F_GETFL, 0); fcntl(s, F_SETFL, flags | O_NONBLOCK);
#endif
		sockaddr_in addr{}; addr.sin_family = AF_INET; addr.sin_port = htons(port);
		if(inet_pton(AF_INET, ip.c_str(), &addr.sin_addr) <= 0) { close_socket(s); return false; }
		int rv = connect(s, (sockaddr*)&addr, sizeof(addr));
		if (rv == 0) { close_socket(s); return true; }
		fd_set wf; FD_ZERO(&wf); FD_SET(s, &wf);
		struct timeval tv; tv.tv_sec = timeout_ms/1000; tv.tv_usec = (timeout_ms%1000)*1000;
		rv = select(s+1, NULL, &wf, NULL, &tv);
		if (rv > 0) {
			int err = 0; socklen_t el = sizeof(err); getsockopt(s, SOL_SOCKET, SO_ERROR, (char*)&err, &el);
			close_socket(s);
			return err == 0;
		}
		close_socket(s);
		return false;
	};

	// open log file in program (executable) directory
	string logpath = "dnstool.log";
#if defined(_WIN32) || defined(_WIN64)
	char modpath[MAX_PATH];
	if (GetModuleFileNameA(NULL, modpath, MAX_PATH) > 0) {
		string mp = modpath; size_t p = mp.find_last_of("\\/");
		if (p != string::npos) logpath = mp.substr(0,p+1) + "dnstool.log";
	}
#else
	// use argv[0] directory if available
	if (argc > 0) {
		string mp = argv[0]; size_t p = mp.find_last_of("/\\");
		if (p != string::npos) logpath = mp.substr(0,p+1) + "dnstool.log";
	}
#endif
	ofstream logf(logpath, ios::app);
	auto nowt = chrono::system_clock::to_time_t(chrono::system_clock::now());
	if (logf) logf << "==== dnstool run: " << std::put_time(localtime(&nowt), "%Y-%m-%d %H:%M:%S") << " ====" << "\n";

	struct Entry { string server, host; double loss, min_ms, avg_ms, max_ms; vector<string> ips; int reachable; int total_ips; unordered_map<string,bool> ip_reachable; };
	vector<Entry> entries;

	// (Removed HTTP page check — no browser-open detection per user request)

	for(auto &sv : servers) {
		if (!include_ipv6 && sv.find(':')!=string::npos) continue; // hide IPv6 servers
		for (auto &host : domains) {
			Stats st; st.min_ms = 1e18; st.max_ms = 0; st.sum_ms = 0;
			set<string> all_ips;
			for(int k=0;k<probes;++k){
				++st.sent;
				vector<string> resp_ips;
				double r = probe_and_get_ips(sv, host, timeout_ms, resp_ips);
				if(r < 0) { platform_sleep_ms(100); continue; }
				++st.recv; st.sum_ms += r; st.min_ms = min(st.min_ms, r); st.max_ms = max(st.max_ms, r);
				for(auto &ip: resp_ips) all_ips.insert(ip);
				platform_sleep_ms(50);
			}
			double loss = (st.sent==0)?100.0:100.0*(st.sent - st.recv)/st.sent;
			double avg = (st.recv==0)?0.0:st.sum_ms / st.recv;
			if(st.recv==0) st.min_ms = 0;

			Entry e; e.server = sv; e.host = host; e.loss = loss; e.min_ms = (st.recv? st.min_ms:0.0); e.avg_ms = avg; e.max_ms = (st.recv? st.max_ms:0.0);
			for(auto &ip: all_ips) e.ips.push_back(ip);
			e.reachable = 0; e.total_ips = 0; e.ip_reachable.clear();
			for(auto &ip: e.ips){
				if (ip.find(':')!=string::npos) continue; // skip ipv6 for now
				++e.total_ips;
				bool r = tcp_connect_timeout(ip, 80, 800);
				if (r) ++e.reachable;
				e.ip_reachable[ip] = r;
			}
			entries.push_back(move(e));
			// log detail for this query will be emitted later with OUT lines
		}
	}

	// compute servers that are 100% loss across all domains
	unordered_map<string, bool> server_has_success;
	for(auto &sv : servers) server_has_success[sv] = false;
	for(auto &e : entries) {
		if (e.loss < 100.0) server_has_success[e.server] = true;
	}

	// print entries, hiding servers with no success, and show returned IPs
	for(auto &e : entries) {
		if (!server_has_success[e.server]) continue; // hide
		string iplist;
		for(size_t i=0;i<e.ips.size();++i){ if(i) iplist += ","; iplist += e.ips[i]; }
		cout << left << setw(18) << e.server << setw(18) << e.host
			 << setw(8) << fixed << setprecision(1) << e.loss
			 << setw(10) << e.min_ms
			 << setw(10) << e.avg_ms
			 << setw(10) << e.max_ms
			 << " Reachable:" << e.reachable << "/" << e.total_ips
			 << "  ReturnedIPs:" << (iplist.empty()?"-":iplist) << "\n";
		if (logf) {
			logf << "OUT server=" << e.server << " host=" << e.host << " loss=" << e.loss << " ips=" << (iplist.empty()?"-":iplist)
				 << " reachable=" << e.reachable << "\n";
			for(auto &ip: e.ips){ logf << "  ip=" << ip << " reachable=" << (e.ip_reachable.count(ip)? (e.ip_reachable[ip]?"yes":"no") : "-") << "\n"; }
		}
	}

	// list hidden servers
	vector<string> hidden;
	for(auto &kv : server_has_success) if (!kv.second) hidden.push_back(kv.first);
	if (!hidden.empty()){
		cout << "\nHidden 100% loss servers:\n";
		for(auto &h : hidden) cout << " - " << h << "\n";
		if (logf) { logf << "Hidden servers:"; for(auto &h:hidden) logf << " " << h; logf << "\n"; }
	}

	if (logf) logf << "==== end run ====" << "\n";

	// summary
	unordered_set<string> visible_servers;
	unordered_set<string> unique_ips;
	int tot_reachable = 0, tot_ips = 0;
	double loss_sum = 0.0; int loss_count = 0;
	for(auto &e: entries){
		if (!server_has_success[e.server]) continue;
		visible_servers.insert(e.server);
		for(auto &ip: e.ips) unique_ips.insert(ip);
		tot_reachable += e.reachable; tot_ips += e.total_ips;
		loss_sum += e.loss; ++loss_count;
	}
	double avg_loss = loss_count? (loss_sum / loss_count) : 0.0;
	cout << "\nSummary:\n";
	cout << "  Visible servers: " << visible_servers.size() << "\n";
	cout << "  Hidden (100% loss): " << hidden.size() << "\n";
	cout << "  Unique returned IPs: " << unique_ips.size() << "\n";
	cout << "  Reachable IPs: " << tot_reachable << " / " << tot_ips << "\n";
	cout << "  Average loss (visible): " << fixed << setprecision(1) << avg_loss << "%\n";
	if (logf) {
		logf << "Summary: visible_servers=" << visible_servers.size() << " hidden=" << hidden.size()
			 << " unique_ips=" << unique_ips.size() << " reachable=" << tot_reachable << " tot_ips=" << tot_ips
			 << " avg_loss=" << avg_loss << "\n";
	}

	cleanup_sockets();
	return 0;
}
