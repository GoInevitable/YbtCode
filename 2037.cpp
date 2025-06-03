#include <bits/stdc++.h>
using namespace std;
bool a[1001];
int main()
{
    int n, m, x = 1, y = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 1)
        {
            if (x == m)
            {
                cout << i << " ";
                a[i] = 1;
                x = 0;
                y++;
            }
            x++;
        }
        if (i == n)
        {
            i = 0;
        }
        if (y == n)
        {
            break;
        }
    }
    return 0;
}
