#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 3005;
int n, a[N];
map<int, int> mp;
int dp[N][N];
int main() {
	freopen("fib.in", "r", stdin);
	freopen("fib.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dp[i][j] = 2;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; ++j) {
			int k = mp[a[j] - a[i]];
			if (k != 0) {
				dp[i][j] = dp[k][i] + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		mp[a[i]] = i;
	}
	printf("%d", ans);
	return 0;
}

