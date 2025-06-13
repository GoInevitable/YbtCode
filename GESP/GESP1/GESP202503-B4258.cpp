#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x % 10 >= 5)
        {
            printf("%d\n", x / 10 * 10 + 10);
        }
        else
        {
            printf("%d\n", x / 10 * 10);
        }
    }
    return 0;
}