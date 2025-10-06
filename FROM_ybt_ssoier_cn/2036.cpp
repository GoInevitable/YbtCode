#include<bits/stdc++.h>
using namespace std;
bool a[1001];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        a[i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<n;j++){
            if((j+1)%i==0){
                a[j] = !a[j];
            }
        }
    }
    bool first = true;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            if(!first) cout<<" ";
            cout<<i+1;
            first = false;
        }
    }
    return 0;
}