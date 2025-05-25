#include <bits/stdc++.h>
using namespace std;
int main() {
    int m,k,cnt=0;
    cin>>m>>k;
    if(m%19==0){
        while(m!=0){
            if(m%10==3){
                cnt++;
            }
        }
        if(cnt>=k){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        return 0;
    }
    cout<<"NO";
    return 0;
}