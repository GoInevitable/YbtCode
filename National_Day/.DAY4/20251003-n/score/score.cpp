#include<bits/stdc++.h>
using namespace std;
int n, m;
int amax=INT_MAX, bmax, t;
int main() {
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t < amax) {
			amax = t;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		if (t > bmax) {
			bmax = t;
		}
	}
	cout << amax - bmax;


	return 0;
}
