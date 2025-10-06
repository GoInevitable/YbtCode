
#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int>> a;
bool cmp(const pair<long long, int> &x, const pair<long long, int> &y)
{
    return x.first < y.first;
}
int main()
{
    freopen("werewolf.in", "r", stdin);
    freopen("werewolf.out", "w", stdout);
    int n;
    cin >> n;

    a.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        long long v;
        cin >> v;
        a.emplace_back(v, i);
    }
    if (n == 1)
    {
        cout << a[0].second;
        return 0;
    }
    sort(a.begin(), a.end(), cmp);
    vector<long long> vv(n);
    for (int i = 0; i < n; i++)
        vv[i] = a[i].first;

    int l = 0, r = n - 1;
    while (l < r)
    {
        long long sum = vv[l] + vv[r];
        long long mid = sum / 2; 
        int pos = upper_bound(vv.begin() + l, vv.begin() + r + 1, mid) - vv.begin() - 1;
        int rp = (pos >= l) ? (pos - l + 1) : 0;
        int all = r - l + 1;
        int lp = all - rp;
        if (lp > rp)
            l++;
        else
            r--;
    }

    cout << a[l].second;
    return 0;
}
