#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (cin >> t; t; --t) {
		stack<unsigned long long int> s;
		for (cin >> n; n; --n) {
			string str;
			cin >> str;
			if (str == "push") {
				unsigned long long x;
				cin >> x;
				s.push(x);
			} else if (str == "pop") {
				if (s.empty()) {
					cout << "Empty" << endl;
				} else {
					s.pop();
				}
			} else if (str == "query") {
				if (s.empty()) {
					cout << "Anguei!" << endl;
				} else {
					cout << s.top() << endl;
				}
			} else {
				cout << s.size() << endl;
			}
		}
	}
	return 0;
}

