#include <bits/stdc++.h>
using namespace std;
int a[110];
int cmp(int x, int y)
{
    return x > y;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int x=a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=1;i<=n;j++){
                if(a[i]==x){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                if(a[i]==x){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}