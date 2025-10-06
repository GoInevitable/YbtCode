#include <iostream>
using namespace std;
int main() {
    int b,c=0,s=0,m=0;
    for(int i=1;i<=12;i++){
        c+=300;
        cin>>b;
        if(c<b){
            m=i;break;
        }
        c-=b;
        int t=c/100 * 100;
        s+=t;
        c-=t;
    }
    if(m)cout<<'-'<<m;
    else cout<<s*1.2+c;
}