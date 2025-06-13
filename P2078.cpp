#include<bits/stdc++.h>
using namespace std;
int a[100001],n;
int find_l(int x){
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
int find_r(int x){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(r+l)/2;
		if(a[mid]>x){
			r=mid-1;
		}else if(a[mid]<x){
			l=mid+1;
		}else{
            l=mid+1;
        }
	}
	if(a[r]==x){
        return r;
    }else{
        return -1;
    }
}
int main(){
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int x;
    for(int i=1;i<=q;i++){
        scanf("%d",&x);
        printf("%d %d\n",find_l(x),find_r(x));
    }
    return 0;
}