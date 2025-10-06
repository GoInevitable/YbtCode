#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	ll k;
	cin >> k;
	while (k--) {
		ll n, e, d;
		scanf("%lld%lld%lld", &n, &e, &d);
		ll PsubQ = sqrt((n - e * d + 2) * (n - e * d + 2) - (n * 4));
		ll PaddQ = n - e * d + 2;
		ll P = (PsubQ + PaddQ) / 2;
		ll Q = PaddQ - P;
		if (P * Q == n && e * d == (P - 1) * (Q - 1) +1 && P && Q) {
			printf("%lld %lld\n", min(P, Q), max(P, Q));
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
