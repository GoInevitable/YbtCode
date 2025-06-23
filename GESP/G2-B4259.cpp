#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++){
            cout << i * j << " ";
        }
        cout << endl;
    }
    return 0;
}//https://www.luogu.com.cn/problem/B4259 B4259 [GESP202503 二级] 等差矩阵