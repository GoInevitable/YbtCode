#include <iostream>
#include <cstdio>
using namespace std;
int a[10011];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        int xx;
        scanf("%d", &xx);
        if (xx == 1)
        {
            int x, v;
            scanf("%d%d", &x, &v);
            a[x] = v;
        }
        else
        {
            int x;
            scanf("%d", &x);
            int w = a[x];
            int sum = n;
            for (int j = 1; j < x; j++)
            {
                if (a[j] > w)
                {
                    sum--;
                }
            }
            for (int j = x + 1; j <= n; j++)
            {
                if (a[j] >= w){
                    sum--;
                }
                    
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
