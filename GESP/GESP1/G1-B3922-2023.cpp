#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        if(i % m != 0){
            printf("%d\n",i);
        }
    }
    return 0;
}//https://www.luogu.com.cn/problem/B3922 B3922 [GESP202312 一级] 小杨报数