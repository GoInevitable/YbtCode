#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[10000010],b[10000010];
bool find(int x){
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
        return true;
    }else{
        return false;
    }
}
int main() {
    int x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int i=1;i<=m;i++){
        if(find(b[i])){
            printf("%d ",b[i]);
        }
    }
    
    return 0;
}