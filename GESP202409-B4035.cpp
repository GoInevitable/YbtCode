#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x%9==0&&x%8!=0)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}