/**
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem //https://www.luogu.com.cn/problem/B4064 B4064 [GESP202412 二级] 寻找数字
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < t; i++)
    {
        int b = sqrt(sqrt(a[i]));
        if (pow(b, 4) == a[i])
        {
            cout << b << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}