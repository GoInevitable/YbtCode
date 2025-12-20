/**  
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem //https://www.luogu.com.cn/problem/B3924 B3924 [GESP202312 二级] 小杨的H字矩阵
 * @license MIT
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==1||j==n){
                printf("|");
            }else if(i==(n+1)/2){
                printf("-");
            }else{
                printf("a");
            }
        }
        printf("\n");
    }
    return 0;
}