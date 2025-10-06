#include <bits/stdc++.h>
using namespace std;
long long n;
int a[100];
int solve(long long x)
{
    int len = 1;
    while (x != 0)
    {
        a[len++] = x % 10;
        x /= 10;
    }
    len--;
    for (int i = 1, j = len; i <= len / 2; i++, j--) // 双指针
    {
        if (a[i] != a[j])
        {
            return false;
        }
    }
    return true;

}

int main()
{
    freopen("abba.in","r",stdin);
	freopen("abba.out","w",stdout);
    cin >> n;
    long long ans = 0;
    for (long long i = 0; i * i * i <= n; i++)
    {
        long long x = i * i * i;
        if (solve(x))
        {
            ans = x;
        }
    }
    cout << ans;
    return 0;
}
