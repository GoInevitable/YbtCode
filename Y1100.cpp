#include<iostream>
using namespace std;
int main(){
	int t=0,n=1,nt=0,ans=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ans+=n;nt++;
		if(nt==n){
			n++;
			nt=0;
		}
	}
	cout<<ans;
	return 0;
}