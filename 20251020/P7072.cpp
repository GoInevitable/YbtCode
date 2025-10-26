#include<bits/stdc++.h>
using namespace std;
int n, w, x, a[607];

int main() {
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		a[x]++;
		int pl = max(1, i * w / 100), num = 0;
		for (int j = 600; j >= 0; --j) {
			num += a[j];
			if (num >= pl) {
				printf("%d ", j);
				break;
			}
		}
	}
	return 0;
}


