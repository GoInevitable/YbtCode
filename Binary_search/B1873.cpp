#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
    int n, m;
    cin >> n >> m;
    int l = 0, r, mid;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > r)
        {
            r = a[i];
        }
    }
    //sort(a + 1, a + n + 1);
    
    while (l <= r)
    {
        mid = (l + r) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > mid)
                sum += a[i] - mid;
        }
        if (sum >= m)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l - 1 << endl;
    return 0;
}