#include<bits/stdc++.h>
using namespace std;
map<int, int> cnt;
const int N = 1e5 + 10;
int a[N], s[N];
int n, m, x, len, ans = 1e9;
int main()
{
    freopen("put.in", "r", stdin);
    freopen("put.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cnt[x]++;
    }
    for (map<int, int>::iterator i = cnt.begin(); i != cnt.end(); ++i)
    {
        a[++len] = i->second;
    }
    sort(a + 1, a + len + 1);
    for (int i = 1; i <= len; i++)
    {
        s[i] = s[i - 1] + a[i]; // 前缀和
    }
    for (int i = 1; i <= len; i++)
    {
        int j = upper_bound(a + i, a + len + 1, a[i] + m) - a - 1; // 找到第一个大于 a[i]+m 的位置 j。
        int sum = s[j] - s[i - 1] + (len - j) * (a[i] + m);
        ans = min(ans, n - sum);
    }
    printf("%d\n", ans);
    return 0;
}
//https://hydro.ac/d/wxc110/p/1083