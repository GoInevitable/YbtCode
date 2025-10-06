#include<bits/stdc++.h>
using namespace std;
const int N = 10e6+10;
int x[N], y = 2;
int ans(int a) {
	for (int i = 1; i <= y; i++) {
		if (a == x[i]) {
			return i;
		} else if (a < x[i]) {
			if (a == x[i] - 1) {
				return i + 1;
			} else {
				return i;
			}
		}
	}
}
int main() {
	//freopen("change.in", "r", stdin);
	//freopen("change.out", "w", stdout);
	x[1] = 1;
	int t, n;
	cin >> t;
	while (x[y - 1] + y <= 1000000) {
		x[y] = x[y - 1] + y, y++;
	}
	x[y] = x[y - 1] + y, y++;
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", ans(n));
	}
	return 0;
}
