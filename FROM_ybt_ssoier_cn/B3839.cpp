#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            cnt+=j;
        }
    }
    cout<<cnt;
    return 0;
}