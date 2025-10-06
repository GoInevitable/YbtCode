#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m,k,cnt=0;
    cin>>m>>k;
    if(m%19==0){
        while(m!=0){
            if(m%10==3){
                cnt++;
            }
            m/=10;
        }
        if(cnt==k){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}//http://ybt.ssoier.cn:8088/problem_show.php?pid=1090 1090：含k个3的数
//https://www.luogu.com.cn/problem/B2078 改编:
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m,k,cnt=0;
    cin>>m>>k;
    while(m!=0){
        if(m%10==3){
            cnt++;
        }
        m/=10;
    }
    if(cnt==k){
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}*/