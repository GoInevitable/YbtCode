#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z, n, m,ans = 0;
    scanf("%d%d%d%d%d", &x, &y, &z, &n, &m);
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m - i; j++)
        {
            if (x * i + j * y + (m - i - j) / z == n && (m - i - j) % z == 0){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}//https://www.luogu.com.cn/problem/B3836 B3836 [GESP202303 二级] 百鸡问题