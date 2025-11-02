#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	vector<ll> cnt(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i]]+=1;
	}
	ll ans = 0;
	for (int x = 1; x <= n; x++)
	{
		if (cnt[x] >= 2)
		{
			ans += (cnt[x] * (cnt[x] - 1) / 2) * (n - cnt[x]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
