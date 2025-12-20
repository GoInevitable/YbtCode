/**
 * @author  Jane Smith
 * @file    1131.cpp
 * @date    2025-11-星期天
 * @version 1.0
 * @problem 1131：基因相关性
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
string a, b;
int main()
{
    double n;
    int cnt = 0;
    cin >> n;
    cin >> a;
    cin >> b;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            cnt++;
        }
    }
    if ((double)cnt / (double)a.size() >= n)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}