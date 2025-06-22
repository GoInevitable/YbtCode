#include<bits/stdc++.h>
using namespace std;
int a[100001],s[100010];
int m,n;
int main(){
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        printf("%d\n",s[y]-s[x-1]);
    }
    return 0;
}