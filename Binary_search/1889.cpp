#include <bits/stdc++.h>
using namespace std;
int n=0, m=0, a[10000010];
long long cnt = 0;

int main()
{
    int x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        if (x <= a[1])
        {
            cnt += a[1] - x;
        }
        else if (x >= a[n])
        {
            cnt += x - a[n];
        }
        else
        {
            int l = 1, r = n, mid;
            while (l <= r)
            {
                mid = (r + l) / 2;
                if (a[mid] >= x)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            cnt += min(a[l] - x, x - a[l - 1]);
        }
    }
    cout << cnt;
    return 0;
}