#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000010];
int find(int x){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(r+l)/2;
		if(a[mid]>=x){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if(a[l]==x){
        return l;
    }else{
        return -1;
    }
}
int main() {
    int x;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    cin>>x;
    cout<<find(x);
    return 0;
}