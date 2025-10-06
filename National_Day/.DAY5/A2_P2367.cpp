#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5 * 1e6+10;
ll a[N];
ll d[N];
int n, p, x, y, z, ans = INT_MAX;
int main() {
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		d[x] += z;
		d[y + 1] -= z;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + d[i];
		if (a[i] < ans) {
			ans = a[i];
		}
	}
	printf("%d", ans);
	return 0;
}
