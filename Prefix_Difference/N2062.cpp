#include<bits/stdc++.h>
using namespace std;
int n,k,L,R,P;
int a[100001],b[100001],c[100001];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&L,&R,&P);
        b[L]+=P;
        b[R+1]-=P;
    }
    for(int i=1;i<=n;i++){
        c[i]=b[i]+c[i-1];
    }
    for(int i=1;i<=n;i++){
        printf("%d ",c[i]);
    }

    return 0;
}