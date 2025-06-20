#include <bits/stdc++.h>
using namespace std;
int a[50001];
int L, n, m;
bool check(int x)
{
    int last = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - last < x)
            ans++;
        else
            last = a[i];
    }
    if (L - last < x)
        ans++;
    if (ans <= m)
        return true;
    else
        return false;
}
int main()
{

    scanf("%d%d%d", &L, &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int l = 1, r = L, mid;
    sort(a + 1, a + n + 1);
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d\n", l - 1);
    return 0;
}