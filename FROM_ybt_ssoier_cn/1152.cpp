#include <bits/stdc++.h>
using namespace std;
double max1(int x, int y, int z)
{
    if (x < y)
    {
        x = y;
    }
    if (x < z)
    {
        x = z;
    }
    return x;
}
int main()
{
    double a, b, c, ans;
    cin >> a >> b >> c;
    ans = max1(a, b, c) / (max1(a + b, b, c) * max1(a, b, b + c)) * 1.0;
    printf("%.3f", ans);
    return 0;
}