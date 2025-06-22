#include <bits/stdc++.h>
using namespace std;
int a[1000010], s[1000010];
int main()
{
    int n, ai, bi;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &ai, &bi);
        a[ai] += 1;
        a[bi + 1] -= 1;
    }
    int max1 = 0;
    for (int i = 0; i <= 1000010; i++)
    {
        s[i] = a[i] + s[i - 1];
        if (max1 < s[i])
        {
            max1 = s[i];
        }
    }
    cout << max1 << endl;
    return 0;
}