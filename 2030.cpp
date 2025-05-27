#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    bool flag = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        flag = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << i << endl;
        }
    }
    return 0;
}
//2030：【例4.16】找素数 http://ybt.ssoier.cn:8088/problem_show.php?pid=2030