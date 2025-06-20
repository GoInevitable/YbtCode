#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,n;
    scanf("%d%d",&x,&n);
    printf("%d",(n + x - 1) % 7 + 1);
    return 0;
}//https://www.luogu.com.cn/problem/B3921 B3921 [GESP202312 一级] 小杨的考试