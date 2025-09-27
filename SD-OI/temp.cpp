#include <bits/stdc++.h>
using namespace std;
int long long  a[2000001];
int main() {
    int cnt=2;
    a[1]=1;
    for(int i=2;i<=2000010;i++){
        a[i]=a[i-1]+cnt;
        cnt++;
        printf("%lld ",a[i]);
    }
    return 0;
}