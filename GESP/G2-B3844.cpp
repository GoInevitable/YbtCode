/**
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem https://www.luogu.com.cn/problem/B3844 B3844 [GESP样题 二级] 画正方形
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char a = 'A';
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", (char)((i + j) % 26 + 'A'));
        }
        printf("\n");
    }
    return 0;
}