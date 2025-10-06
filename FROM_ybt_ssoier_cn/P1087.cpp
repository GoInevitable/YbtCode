#include <bits/stdc++.h>
using namespace std;
int gcd(int m,int n)
{

    long t;
    while (m != 0)
    {
        if (m < n)
        {
            t = m;
            m = n;
            n = t;
        }
        m = m % n;
    }
    return n;
}
int main()
{
    int m, n;
    cin >> m >> n;
    cout<<(m*n)/gcd(m,n);
    return 0;
}