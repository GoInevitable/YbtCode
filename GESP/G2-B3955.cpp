/**
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem //https://www.luogu.com.cn/problem/B3955 小杨的日字矩阵
 * @license MIT
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==1||j==n){
                cout<<'|';
            }else if(i==1||i==n||i==(n+1)/2){
                cout<<'-';
            }else{
                cout<<'x';
            }
        }
        cout<<endl;
    }
    return 0;
}
