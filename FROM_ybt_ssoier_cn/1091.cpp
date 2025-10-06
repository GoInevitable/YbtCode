#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0, t;//v:某一阶乘项的值
    for(int i = 1; i <= n; i++)
    {
        t = 1;
        for (int j = 1; j <= i; j++){
             t *= j;
        }
           
        ans += t;
    }
    cout << ans;
    return 0;
}
//http://ybt.ssoier.cn:8088/problem_show.php?pid=1091