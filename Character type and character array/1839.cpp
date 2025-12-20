/** 
 * @author  Jane Smith
 * @file    Y2050.cpp
 * @date    2025-11-星期六
 * @version 1.0
 * @problem 1839：YBT:[05NOIP提高组]谁拿了最多奖学金
 *                LUOGGU:P1051 [NOIP 2005 提高组] 谁拿了最多奖学金
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin >> n;
    string name;
    int s, sc, p;
    char g, w;
    int max_m = -1;
    string max_name;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> s >> sc >> g >> w >> p;
        int sum = 0;
        if (s > 80 && p >= 1)
            sum += 8000;
        if (s > 85 && sc > 80)
            sum += 4000;
        if (s > 90)
            sum += 2000;
        if (s > 85 && w == 'Y')
            sum += 1000;
        if (sc > 80 && g == 'Y')
            sum += 850;

        total += sum;
        if (sum > max_m)
        {
            max_m = sum;
            max_name = name;
        }
    }
    cout << max_name << endl
         << max_m << endl
         << total << endl;
    return 0;
}