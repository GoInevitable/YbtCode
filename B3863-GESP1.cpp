#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 0, y = 0, z = 0, q = 0;
    cin >> x >> y >> z >> q;
    if (2 * x + 5 * y + 3 * z <= q)
    {
        cout << "Yes" << endl
             << q - 2 * x - 5 * y - 3 * z;
    }
    else
    {
        cout << "No" << endl
             << 2 * x + 5 * y + 3 * z - q;
    }
    return 0;
}
//B3863 [GESP202309 一级] 买文具 https://www.luogu.com.cn/problem/B3863