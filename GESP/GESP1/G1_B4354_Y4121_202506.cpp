#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,t,ans;
    cin>>n>>k>>t;
    ans=t*k;
    if(ans>n)
        ans=n;
    cout<<ans;
    return 0;
}
//B4354 [GESP202506 一级] 假期阅读
//https://www.luogu.com.cn/problem/B4354
//http://ybt.ssoier.cn:8088/problem_show.php?pid=4121