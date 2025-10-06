#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 0, c = 0;
    cin >> a;
    for (int i = 1; i * i <= a; i++)
    {
        if ((a % i) == 0)
            c++;
    }
    cout << c;
    return 0;
}//https://www.luogu.com.cn/problem/B3834