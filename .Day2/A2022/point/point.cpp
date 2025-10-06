#include<bits/stdc++.h>
using namespace std;
int n, k, ans, f[505][505];
struct poin {
	int x, y;
} point[1001];
bool cmp(poin a, poin b) {
	if (a.x != b.x)return a.x < b.x;
	else return a.y < b.y;
}
int get(int xa, int ya, int xb, int yb) {
	return abs(xa - xb) + abs(ya - yb) -1;
}
int main() {
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &point[i].x, &point[i].y);
	}
	sort(point + 1, point + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for(int z=0;z<=k;z++){
			f[i][z]=z+1;
			for(int j=1;j<i;j++){
				int lent =get(point)
			}
		}
	}
	return 0;
}
