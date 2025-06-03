#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double ans = 0, t;
    for(int i = 1; i <= n; i++)
    {
        t = 1;
        for (int j = 1; j <= i; j++){
             t *= j;
        }
        ans += 1.0/t;
    }
    printf("%.10f",ans+1);
    return 0;
}
//http://ybt.ssoier.cn:8088/problem_show.php?pid=1092 求出e的值