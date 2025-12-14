#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],c[110];
char ac[101],bc[101];
int main(){
    cin>>ac>>bc;
    int lena=strlen(ac),lenb=strlen(bc);
    for(int i=1;i<=lena;i++){
        a[i]=ac[lena-i]-48;
    }
    for(int i=1;i<=lenb;i++){
        b[i]=bc[lenb-i]-48;
    }
    
    return 0;
}