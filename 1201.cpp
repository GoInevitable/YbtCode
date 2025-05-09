#include<bits/stdc++.h>
using namespace std;
long long fib(int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

int main(){
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cout<<fib(a);
    }
    return 0;
}