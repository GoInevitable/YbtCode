#include <bits/stdc++.h>
using namespace std;
char mp[1010][1010];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool st[1010][1010];
int solve(int n, int m, int k, int x, int y, int d) {
	int ans = 1;
	int nx, ny;
	for (int i = 1; i <= k; i++) {
		if (d == 0) {
			nx = x;
			ny = y + 1;
		} else if (d == 1) {
			nx = x + 1;
			ny = y;
		} else if (d == 2) {
			nx = x;
			ny = y - 1;
		} else {
			nx = x - 1;
			ny = y;
		}
		//memset(st, 0, sizeof st), 
        //st[x][y] = 1;
		if (mp[nx][ny] == 'x' || nx < 1 || nx > n || ny < 1 || ny > m) {
			d = (d + 1) % 4;
		} else {

			if (st[x][y] == 0) ans++;
			st[x][y] = true;
			x = nx;
			y = ny;
		}
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k, x, y, d;
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> mp[i][j];
			}
		}
		cout << solve(n, m, k, x, y, d) << endl;
	}
	return 0;
}
