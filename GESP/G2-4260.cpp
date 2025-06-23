#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y, m, d, h, k, ds;
    cin >> y >> m >> d >> h >> k;
    h += k;
    while (h >= 24) {
        h -= 24;
        d += 1;
    }
    while (true) {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            ds = 31;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            ds = 30;
        }
        else if (m == 2)
        {
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            {
                ds = 29;
            }
            else
            {
                ds = 28;
            }
        }
        if (d > ds)
        {
            d -= ds;
            m += 1;
            if (m > 12)
            {
                m = 1;
                y += 1;
            }
        }
        else
        {
            break;
        }
    }
    cout << y << " " << m << " " << d << " " << h;
}//https://www.luogu.com.cn/problem/B4260 B4260 [GESP202503 二级] 时间跨越
