#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000010];
int find(int x) {
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (r + l) / 2;
		if (a[mid] >= x) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (a[l] == x) {
		return l;
	} else {
		return -1;
	}
}
int main() {
	int x;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		printf("%d ", find(x));
	}
	return 0;
}
