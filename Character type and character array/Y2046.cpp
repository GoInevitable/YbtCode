/** 
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem 2046：【例5.15】替换字母
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
char s[201];
int main()
{
    char a, b;
    cin.getline(s, 201);
    cin >> a >> b;
    int len = strlen(s);
    for (int i = 1; i <= len; ++i)
    {
        if (s[i] == a)
        {
            s[i] = b;
        }
    }
    cout << s;
    return 0;
}