#include <bits/stdc++.h>
using namespace std;


bool check(string s) { // 判断s的合法
	int len = s.size();
	// 第一条不合法性
	vector<char> c;
	for (int i = 0; i < len; i++) {
		if (s[i] == '.' || s[i] == ':') c.push_back(s[i]);
	}
	if (c.size() != 4 || c[0] != '.' || c[1] != '.' || c[2] != '.' || c[3] != ':') return false;
	// 第二条和第三条是否合法
	s = s + ".";
	string ss;
	int cnt = 0;
	for (int i = 0; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') ss += s[i];
		else {
			// 检查每一个解析出来的数是否合法
			int lens = ss.size();
			if (lens > 5) return false;
			
			if ((lens >= 2 && ss[0] == '0') || lens == 0) return false;
			cnt++;
			if (cnt <= 4 && stoi(ss) > 255) return false;
			if (cnt == 5 && stoi(ss) > 65535) return false;
			ss = "";
		}
	}
	return true;
}

map<string, int> ser;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 == "Server") {
			if (!check(s2)) cout << "ERR" << endl;
			else {
				if (ser[s2]) cout << "FAIL" << endl;
				else cout << "OK" << endl, ser[s2] = i;
			}
		} else {
			if (!check(s2)) cout << "ERR" << endl;
			else {
				if (ser[s2]) cout << ser[s2] << endl;
				else cout << "FAIL" << endl;
			}
		}
	}
	
	return 0;
}


