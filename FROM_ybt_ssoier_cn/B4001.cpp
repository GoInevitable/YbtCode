#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        if(i*i*i==n){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}//https://www.luogu.com.cn/problem/B4001