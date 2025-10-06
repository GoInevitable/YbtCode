#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long a[N];
map<long long, int> mp;
int main() {
	freopen("werewolf.in", "r", stdin);
	freopen("werewolf.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], a[i] *= 2;
		mp[a[i]] = i;
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = n;
	for (int i = 1; i < n; i++) {
		long long mid = (a[l] + a[r]) / 2;
		int k = lower_bound(a + l, a + r + 1, mid) - a;
		int cnt1 = k - l, cnt2 = r - k;
		if (a[k] == mid) cnt1++;
		else cnt2++;
		if (cnt1 >= cnt2) r--;
		else l++;
	}
	cout << mp[a[l]];
	return 0;
}

