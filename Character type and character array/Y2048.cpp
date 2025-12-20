/** 
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem 2048：【例5.18】串排序
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
string s[30];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}