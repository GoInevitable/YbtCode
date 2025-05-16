#include <bits/stdc++.h>
using namespace std;
int main() {
    int max1=0,min1=INT_MAX,x=0,n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        max1=max(x,max1);
        min1=min(x,min1);
    }
    cout<<max1-min1;
    return 0;
}
//1112：最大值和最小值的差 http://ybt.ssoier.cn:8088/problem_show.php?pid=1112
