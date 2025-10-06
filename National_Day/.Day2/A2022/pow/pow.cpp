#include<bits/stdc++.h>
using namespace std;
int a, b;
long long ans = 1;
int main() {
    freopen("pow.in", "r", stdin);
    freopen("pow.out", "w", stdout);
	cin >> a >> b;
	if (a == 1) {
		cout << 1;
		return 0;
	}
	for (; b && ans <= 1e9; b--) {
		ans *= a;
	}
	if (ans > 1e9) {
		cout << -1;
	} else {
		cout << ans;
	}
	return 0;
}