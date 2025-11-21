/**      
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem //https://www.luogu.com.cn/problem/B3837 B3837 [GESP202303 二级] 画三角形
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    char s = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%c", s);
            s++;
            if (s > 'Z')
            {
                s = 'A';
            }
        }
        printf("\n");
    }
    return 0;
}