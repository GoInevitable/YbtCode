#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
    int n, d, x;
    cin >> n >> d;
    for (int i = 1; i <= d; i++)
    {
        scanf("%d", &x);
        a[x] += i;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}//https://www.luogu.com.cn/problem/B3867 B3867 [GESP202309 三级] 小杨的储蓄



