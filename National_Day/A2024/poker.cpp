//https://www.luogu.com.cn/problem/P11227
//P11227 [CSP-J 2024] 扑克牌

#include <bits/stdc++.h>
using namespace std;
int k = 0;
string a[52];
int n;
bool solve(string s)
{
    if (k == 0)
    {
        a[0] = s;
        k++;
        return 0;
    }
    for (int i = 0; i < k; i++)
    {
        if (a[i] == s)
        {
            return 1;
        }
    }
    a[k] = s;
    k++;
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        solve(s);
    }
    // cout<<k<<" ";
    cout << 52 - k;
    return 0;
}
