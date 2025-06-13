#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        bool flag = 0;
        for (int x = 1; x * x <= a && !flag; x++)
        {
            for (int y = 1; y * y <= a && !flag; y++)
            {
                if (x * x + y * y == a)
                {
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
//https://www.luogu.com.cn/problem/B4002 B4002 [GESP202406 二级] 平方之和