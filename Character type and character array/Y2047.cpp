/** 
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem //2047：【例5.16】过滤空格 - http://ybt.ssoier.cn:8088/problem_show.php?pid=2047
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
char s[201];
int main()
{
    cin.getline(s, 201);
    int len = strlen(s);
    bool space = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == ' ')
        {
            if (space)
            {
                continue;
            }
            else
            {
                space = 1;
                cout << ' ';
            }
        }
        else
        {
            space = 0;
            cout << s[i];
        }
    }
    return 0;
}
