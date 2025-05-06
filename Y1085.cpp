#include <bits/stdc++.h>
using namespace std;
int main()
{
    double h, sum;
    cin >> h;
    sum = h;
    for (int i = 1; i < 10; i++)
    {
        h /= 2;
        sum += h + h;
    }
    cout << sum << endl
         << h / 2;
    return 0;
}