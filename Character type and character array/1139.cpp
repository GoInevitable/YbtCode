/** 
 * @author  Jane Smith
 * @file    1139.cpp
 * @date    2025-12-星期六
 * @version 1.0
 * @problem 整理药名
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
string s[101];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i][0] >= 'a' && s[i][0] <= 'z')
        {
            s[i][0] -= 32;
        }
        for (int j = 1; j < s[i].size(); j++)
        {
            if (s[i][j] >= 'A' && s[i][j] <= 'Z')
            {
                s[i][j] += 32;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }

    return 0;
}