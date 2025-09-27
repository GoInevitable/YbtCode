#include <bits/stdc++.h>
using namespace std;

int a[1002][5];

void solve(int x, int y)
{
    x--;
    y--; // 转换为0-based索引
    int l = max(a[x][0], a[y][0]);
    int r = min(a[x][2], a[y][2]);
    int t = max(a[x][1], a[y][1]);
    int b = min(a[x][3], a[y][3]);

    printf("%d\n", max(0, r - l) * max(0, b - t));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int m, x, y;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        solve(x, y);
    }
    return 0;
}