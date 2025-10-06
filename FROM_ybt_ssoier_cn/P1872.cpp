#include<bits/stdc++.h>
using namespace std;
int a[100001];
int gcd(int m,int n)
{

    long t;
    while (m != 0)
    {
        if (m < n)
        {
            t = m;
            m = n;
            n = t;
        }
        m = m % n;
    }
    return n;
}
int main(){
    int n,ans;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        a[i]=gcd(a[i-1],a[i]);
    }
    cout<<a[n-1];

    return 0;
}