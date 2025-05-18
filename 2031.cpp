#include <bits/stdc++.h>
using namespace std;
int main()
{
    int e;
    for (int i = 1000; i <= 9999; i++)
    {
        e = sqrt(i);
        if ((i % 10 == i / 10 % 10) && (i / 100 % 10 == i / 1000) && (e * e == i))
        {
            cout << i << ' ';
        }
    }
    return 0;
}
//http://ybt.ssoier.cn:8088/problem_show.php?pid=2031 2031：【例4.17】四位完全平方数