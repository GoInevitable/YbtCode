/**
 * @author  Jane Smith
 * @file    2050.cpp
 * @date    2025-11-星期六
 * @version 1.0
 * @problem 2050：【例5.20】字串包含
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    if (s1.size() < s2.size())
    {
        swap(s1, s2);
    }
    s1 = s1 + s1;
    if (s1.find(s2) != s1.npos)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}