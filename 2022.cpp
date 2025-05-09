#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    double sum = 0.0;
    int n = 0;
    while (sum < m)
    {
        n++;
        sum += 1.0 / n;
    }
    cout << n;
    return 0;
}
//http://ybt.ssoier.cn:8088/problem_show.php?pid=2022 2022：【例4.7】最小n值