#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    while(n!=0){
        cout<<n%10<<" ";
        n/=10;
    }
    return 0;
}