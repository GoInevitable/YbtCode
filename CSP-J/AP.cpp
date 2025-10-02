#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) q.push(i);
    int sum=0;
    int ans;
    while (!q.empty())
    {
        sum++;
        int cnt = 0;
        while(1){
            cnt++;
            int cur = q.front();
            q.pop();
            if(cnt==1||cnt==4){
                if(cur==n) ans=cur;
            }else q.push(cur);
            if(cur > q.front()) break;
        }
    }
    
    return 0;
}