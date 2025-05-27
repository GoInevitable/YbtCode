#include<bits/stdc++.h>
using namespace std;
int main(){
    double k,c,f;
    cin>>k;
    c=k-273.15;
    f=c*1.8+32;
    if(f>212){
        printf("Temperature is too high!");
    }else{
        printf("%.2f %.2f",c,f);
    }
    return 0;
}