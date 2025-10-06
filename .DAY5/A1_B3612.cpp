#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int a[N];
long long b[N];
int n, m, x, y;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		printf("%d\n", b[y] - b[x-1]);
	}
	return 0;
}
