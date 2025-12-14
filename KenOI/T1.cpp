#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0;
		cin >> n;
		for (int i = 1; i * i <= n; i++) {
			if ((i * i) % 3 == 0) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
