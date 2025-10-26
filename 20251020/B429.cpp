#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101];
int main() {
	int n, m, sum;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (sum - a[i] == m) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
