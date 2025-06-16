#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(j==1||j==m||i==j){
                cout<<'+';
            }else{
                cout<<'-';
            }
        }
        cout<<endl;
    }

    return 0;
}//https://www.luogu.com.cn/problem/B4037 B4037 [GESP202409 二级] 小杨的 N 字矩阵