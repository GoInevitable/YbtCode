//https://www.luogu.com.cn/problem/P11228
//P11228 [CSP-J 2024] 地图探险

#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool st[1005][1005];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k, x, y, d;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin>>mp[i][j];
			}
		}
		int ans = 1;
		memset(st, 0, sizeof st), st[x][y] = 1;
		for (int i = 1; i <= k; i++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'x') {
				d = (d + 1) % 4;
			} else {
				if (st[nx][ny] == 0) ans++;
				st[nx][ny] = 1;
				x = nx, y = ny;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
