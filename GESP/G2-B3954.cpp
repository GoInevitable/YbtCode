#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 1, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (ans * x > 1000000)
        {
            cout << ">1000000";
            return 0;
        }
        else
        {
            ans *= x;
        }
    }
    cout << ans;
    return 0;
}
//https://www.luogu.com.cn/problem/B3954 B3954 [GESP202403 二级] 乘法问题