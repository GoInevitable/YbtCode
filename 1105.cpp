#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    int i,n=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i--;i>=0;i--){
        cout<<a[i]<<" ";
    }
    return 0;
}