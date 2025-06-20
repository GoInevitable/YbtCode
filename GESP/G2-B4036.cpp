#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int t = a[i];
        int sum = 0;
        while (t != 0)
        {
            sum += t % 10;
            t /= 10;
        }
        if (sum % 7 == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}//https://www.luogu.com.cn/problem/B4036 B4036 [GESP202409 二级] 数位之和