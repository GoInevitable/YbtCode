#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, r, cnt = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
        {                  
            cnt = cnt + i; 
        }
    }
    cout << cnt << endl;
    return 0;
}