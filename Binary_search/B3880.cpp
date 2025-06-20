#include <bits/stdc++.h>
using namespace std;
int n, m, l, s;
struct Node
{
    int l, s;
};
Node N[100001];
int main()
{
    cin >> n >> m >> l >> s;
    N[1].l = l;
    N[1].s = s;
    for (int i = 2; i <= n; i++)
    {
        N[i].l = ((N[i - 1].l * 37011 + 10193) % 10000) + 1;
        N[i].s = ((N[i - 1].s * 73011 + 24793) % 100) + 1;
    }
    //sort(N + 1, N + n + 1, cmp);
    int left = 1, right = 10000, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum += N[i].l / mid * N[i].s;
        }
        if (sum >= m)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << left - 1 << endl;
    return 0;
}