#include <bits/stdc++.h>
using namespace std;
int solve(int x, int y)
{
    int d = y - x;
    if (d == 0)
        return 0;
    if (d > 0)
    {
        if (d % 2 == 1)
            return 1;
        else if (d / 2 % 2 == 1)
            return 2;
        else
            return 3;
    }
    else
    {
        if (d % 2 == -1)
            return 2;
        else
            return 1;
    }
}
int main()
{
    freopen("red.in", "r", stdin);
    freopen("red.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        int a, b;
        cin >> a >> b;
        /*if (a == b)
        {
            ans = 0;
        }
        else if (a < b)
        {
            int d = b - a;
            if (d % 2 == 1) // 为奇数，+1
            {
                ans = 1;
            }
            else
            {
                if ((d / 2) % 2 == 1) // 一半为奇数，+二
                {
                    ans = 2;
                }
                else // 如果 (b−a)/2为偶数先加上两次奇数，再减去一个偶数
                {
                    ans = 3;
                }
            }
        }
        else // a>b
        {
            int d = a - b;
            if (d % 2 == 1) //-偶
            {
                ans = 2;
            }
            else
            {
                ans = 1;
            }
            /*如果  ( a − b ) (a−b) 为奇数，那么需要两次操作：
            第一次操作：将  a a 增加一个奇数  x x 使得  a + x a+x
            变成  a ′ a  ′   第二次操作：将  a ′ a  ′   再减少
            ( a − b + x ) (a−b+x) 的偶数  y y，使得  a ′ − y = b a  ′  −y=b
             具体步骤为：增加一个奇数1，使得 ( a + 1 − b ) (a+1−b)为偶数，
             然后减去偶数 ( a − b + 1 ) (a−b+1)即可。
        }*/
        cout << solve(a,b) << endl;
    }
    return 0;
}