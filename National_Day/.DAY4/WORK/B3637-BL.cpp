#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int a[N];
bool check(vector<int> b) {
	int len = b.size();
	for (int i = 1; i < len; i++) {
		if (b[i] <= b[i - 1]) {
			return false;
		}
		return true;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		vector<int> b;
		for (int j = 0; j < n; j++) {
			if (n & (1 << j)) {
				b.push_back(a[j]);
			}
		}
		if (check(b)) {
			ans = max(ans, (int)b.size());
		}
	}
	cout << ans;
	return 0;
	//暴力枚举
}
