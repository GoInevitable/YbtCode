#include<iostream>
using namespace std;
bool mp[1010][1010];
bool mp1[1010][1010];
int n, m, k, x, y, d;
int solve() {
	int sum = 0;
	int x1 = 0, y1 = 0;
    mp1[x][y] = 1;
	for (int i = 1; i <= k; i++) {
		if (d == 0) {
			x1 = x;
			y1 = y + 1;
		} else if (d == 1) {
			x1 = x + 1;
			y1 = y;
		} else if (d == 2) {
			x1 = x;
			y1 = y - 1;
		} else {
			x1 = x - 1;
			y1 = y;
		}
		if (mp[x1][y1] == 0 && x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m) {
			mp[x1][y1] = 1;
            x=x1;
            y=y1;
		} else {
			d = (d + 1) % 4;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mp1[i][j] == 1) {
				sum++;
			}
		}
	}
	return sum;
}
int main() {
	int t;
	char temp;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				scanf("%c", &temp);
				if (temp == 'x') {
					mp[n][m] = true;
				} else {
					mp[n][m] = false;
				}
			}
		}
		/*for (int j = 0; j <= n + 1; j++) {
			for (int k = 0; k <= m + 1; k++) {
				cout<<mp[j][k];
			}
			cout<<endl;
		}*/
		printf("%d", solve());
	}
	return 0;
}