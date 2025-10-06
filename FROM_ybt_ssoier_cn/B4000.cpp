#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, m, s, k, t;
    cin >> h >> m >> s >> k;
    t = h * 3600 + m * 60 + s + k;
    cout << t / 3600 << " " << t / 60 % 60 << " " << t % 60;
    return 0;
}