#include<iostream>
using namespace std;
int main(){
    int n=0,x=0,y=0;
    cin>>n>>x>>y;
    if(y%x==0){
        cout<<n-(y/x);
    }else{
        cout<<n-(y/x)-1;
    }
    return 0;
}