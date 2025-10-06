#include <bits/stdc++.h>
using namespace std;
char s[201];
int main()
{
    char a, b;
    cin.getline(s, 201);
    cin >> a >> b;
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == a)
        {
            s[i] = b;
        }    
    }
    cout << s;
    return 0;
}
// http://ybt.ssoier.cn:8088/problem_show.php?pid=2046 2046：【例5.15】替换字母
