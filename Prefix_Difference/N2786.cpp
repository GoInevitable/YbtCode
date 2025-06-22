#include <bits/stdc++.h>
using namespace std;
int b[1000010], s[1000010];
int main()
{
    int n, m, l, r, ans = 0;
    cin >> n >> m;
    while (m--)
    {
        scanf("%d%d", &l, &r);
        b[l] += 1;
        b[r + 1] -= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] = b[i] + s[i - 1];
        if (s[i] % 2 == 1)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}