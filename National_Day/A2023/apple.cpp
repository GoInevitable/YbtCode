//https://www.luogu.com.cn/problem/P9748
//P9748 [CSP-J 2023] 小苹果
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0, cnt = 0;
    cin >> n;
    while (n)
    {
        cnt++;
        if (n % 3 == 1 && ans == 0)
        {
            ans = cnt;
        }
        if (n % 3 == 0)
        {
            n -= n / 3;
        }
        else
        {
            n -= n / 3 + 1;
        }
    }
    cout << cnt <<' '<< ans;
    return 0;
}