#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int main()
{
    int m;
    cin >> m;
    for (int i = 1; i <= 1000000; i++)
    {
        a[i] = a[i - 1] + i;
    }
    for (int i = 1; i <= m / 2 + 1; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (a[i] - a[j - 1] > m)
            {
                break;
            }
            if (a[i] - a[j - 1] == m && i != j)
            {
                printf("%d %d\n", j, i);
            }
        }
    }
    return 0;
}
