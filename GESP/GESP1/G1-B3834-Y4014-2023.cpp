#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, l, r, ans = 0;
    cin >> k >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (i % 10 == k || i % k == 0)
        {
            ans += i;
        }
    }
    cout << ans;
    return 0;
}//https://www.luogu.com.cn/problem/B3864 B3864 [GESP202309 一级] 小明的幸运数