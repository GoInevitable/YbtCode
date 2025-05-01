#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    int i,n=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=1;j<n;j++){
        cout<<a[j]<<" ";
    }
    cout<<a[0];
    return 0;
}