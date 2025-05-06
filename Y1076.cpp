#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    int ans=0,t=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if((a>=90&&a<=140)&&(b>=60&&b<=90)){
            t++;
            if(t>ans){
                ans=t;
            }
        }else{
            t=0;
        }
    }
    cout<<ans;
    return 0;
}