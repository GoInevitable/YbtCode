#include <bits/stdc++.h>
using namespace std;
double a[301];
int main()
{
    double sum = 0, ans, c = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i < n - 1; i++)
    {
        sum += a[i];
    }
    ans = sum / (n - 2);
    for (int i = 1; i < n - 1; i++)
    {
        if (abs(a[i] - ans) > c)
        {
            c = abs(a[i] - ans);
        }
    }
    printf("%.2f %.2f", ans, c);
    return 0;
}
//1114：白细胞计数 http://ybt.ssoier.cn:8088/problem_show.php?pid=1114