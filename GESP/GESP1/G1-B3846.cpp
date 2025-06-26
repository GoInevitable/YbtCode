#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, ans = 0;
    scanf("%d %d", &a, &b);
    for (int i = a + 1; i < b; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            ans += i;
        }
    }
    printf("%d", ans);
    return 0;
}