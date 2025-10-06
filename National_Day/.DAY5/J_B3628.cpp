#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N];
bool check(ll init, int n){
    ll cur = init;
    for(int i=1;i<=n;i++){
        cur += a[i];
        if(cur <= 0) return false;
    }
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    ll sumNeg = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<0) sumNeg += -1LL*a[i];
    }
    if(sumNeg==0){
        printf("1\n");
        return 0;
    }
    ll l = 1, r = sumNeg + 1; // 上界为所有负数绝对值之和 + 1 足够
    while(l<r){
        ll mid = (l + r) >> 1;
        if(check(mid, n)) r = mid;
        else l = mid + 1;
    }
    printf("%lld\n", l);
    return 0;
}
