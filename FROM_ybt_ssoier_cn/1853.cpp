#include <bits/stdc++.h>
using namespace std;
int mouths[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int n,k=4,cnt=0;
    cin>>k;
    for(int i=1998;i<n;i++){
        if(i%4==0&&i%100!=0||i%400==0){
            k+= 366;
        }else{
            k+=365;
        }
        k = k%7;
    }
    for(int i=1;i<=12;i++){
        k+=12;
        if(k%7==5){
            cnt++;
        }
        k -= 12;
        k+=mouths[i];
        if(i%4==0&&i%100!=0||i%400==0){
            k++;
        }
        k%=7;
    }
    cout<<cnt;

    return 0;
}