#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e8 + 10;
int a[N],prime[N],idx;
void init(int x){
	for(int i=2;i<=x;i++){
		if(a[i]==0) prime[++idx] = i;
		for(ll j=1;prime[j]*i<=x;j++){
			a[prime[j]*i] = 1;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
	int n,t;
	cin>>n>>t;
	init(n);
	while(t--){
		int k;
		scanf("%d",&k);
		printf("%d\n",prime[k]);
	}
	return 0;
}
