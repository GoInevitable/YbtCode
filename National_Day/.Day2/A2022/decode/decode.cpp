#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	int k;
	cin >> k;

	while (k--) {
		ll n, d, e;
		cin >> n >> d >> e;
		ll m = n - e * d + 2;
		if (m < 2) {
			cout << "NO" << endl;
			continue;
		}

		bool flag = false;
		ll p = 0, q = 0;

		for (ll i = 1; i <= m / 2; i++) {
			ll j = m - i;
			if (i * j == n) {
				p = i;
				q = j;
				flag = true;
				break;
			}
		}

		if (flag) {
			if (p > q) swap(p, q);
			cout << p << " " << q << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
