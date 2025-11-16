#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, num = 1, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        num = num * i % 1000000;
        sum = (sum + num) % 1000000;
    }
    cout << sum;
    return 0;
}