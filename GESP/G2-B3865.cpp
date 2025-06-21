#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || i + j == n + 1)
            {
                printf("+");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}//https://www.luogu.com.cn/problem/B3865 B3865 [GESP202309 二级] 小杨的 X 字矩阵