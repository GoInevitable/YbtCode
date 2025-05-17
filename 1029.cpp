#include <bits/stdc++.h>
using namespace std;
int main()
{
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    cout<<fixed<<setprecision(3)<<sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
    return 0;
}