/** 
 * @author  Jane Smith
 * @file    Y2049.cpp
 * @date    2025-11-星期六
 * @version 1.0
 * @problem p2049：【例5.19】字符串判等
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[201];
    char b[201];
    cin.getline(a, 201);
    cin.getline(b, 201);
    int lena = strlen(a);
    int lenb = strlen(b);
    int la = 0, lb = 0;
    while (true)
    {
        while (la < lena && a[la] == ' ')
            la++;
        while (lb < lenb && b[lb] == ' ')
            lb++;
        if (la >= lena && lb >= lenb)
        {
            cout << "YES";
            return 0;
        }
        if (la >= lena || lb >= lenb)
        {
            cout << "NO";
            return 0;
        }
        char ca = a[la], cb = b[lb];
        if (ca >= 'A' && ca <= 'Z')
        {
            ca = ca - 'A' + 'a';
        }
        if (cb >= 'A' && cb <= 'Z')
        {
            cb = cb - 'A' + 'a';
        }
        if (ca != cb)
        {
            cout << "NO";
            return 0;
        }
        la++;
        lb++;
    }
    return 0;
}