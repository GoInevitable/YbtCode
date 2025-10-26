#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> t[N];
int l[N];
int dp[105][N];
int main()
{
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int n, k, q;
		scanf("%d%d%d", &n, &k, &q);
		for (int i = 1; i <= n; i++)
		{
			t[i].clear();
			scanf("%d", &l[i]);
			for (int j = 1; j <= l[i]; j++)
			{
				int x;
				scanf("%d", &x);
				t[i].push_back(x);
			}
		}
		memset(dp, -1, sizeof dp);
		dp[0][1] = 0;
		for (int r = 1; r <= 100; r++)
		{
			int *cur = dp[r];      // 当前层指针
			int *prev = dp[r-1];   // 上一层指针
			for (int i = 1; i <= n; i++)
			{
				int len = k + 1;
				int size_i = l[i];              // 缓存长度
				vector<int>& edges = t[i];      // 使用引用
				for (int j = 0; j < size_i; j++)
				{
					int d = edges[j];           // 直接访问边
					len++;
					if (len >= 2 && len <= k)
					{
						if (cur[d] == -1)
							cur[d] = i;
						else if (cur[d] != i)
							cur[d] = 0;
					}
					if (prev[d] != -1 && prev[d] != i)
						len = 1;
				}
			}
		}
		while (q--)
		{
			int r, c;
			scanf("%d%d", &r, &c);
			if (dp[r][c] != -1)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}
