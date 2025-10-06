#include<bits/stdc++.h>
using namespace std;
int main(){
    int sh,sm,eh,em;
    cin>>sh>>sm>>eh>>em;
    if(sm>em){
        em+=60;
        eh--;
    }
    cout<<(eh-sh)*60+(em-sm);
    return 0;
}