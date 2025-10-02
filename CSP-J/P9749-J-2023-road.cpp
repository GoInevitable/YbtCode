#include <bits/stdc++.h>
using namespace std;
long long v[100010],a[100010];
long long n,d,s,pay;
int main() {
    cin>>n>>d;
    for(int i=1;i<n;i++){
    	scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    }
    if(n==1){
    	pay=0;
    }else if(n==2){
    	pay = ceil(double(v[1])/d)*a[1];
    }else{
    	int l=1,r=2;
    	while(r<=n){
    		while(a[r]>a[l]){
    			r++;
    			if(r==n){
    				break;
    			}
    		}
    		long long  temp_s=0;
    		for(int i=l;i<r;i++){
    			temp_s+=v[i];
    		}
    		temp_s-=s;
    		if(temp_s%d==0){
    			pay+=(temp_s/d)*a[l];
    			s=0;
    		}else{
    			pay += (temp_s/d+1)*a[l];
    			s=(temp_s/d+1)*d-temp_s;
    		}
    		l=r;
    		r++;
    	}
    }
    cout<<pay;
    //printf("%d",pay);
    return 0;
}