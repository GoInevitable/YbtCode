/**
 * @author  Jane Smith
 * @file    Y1129.cpp
 * @date    2025-11-星期六
 * @version 1.0
 * @problem 1129：统计数字字符个数
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 255 + 1;
char s[N];
int main()
{
    int sum = 0;
    cin.getline(s, 255);
    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] <= '9' && s[i] >= '0')
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}