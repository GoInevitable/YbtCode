#include<iostream>
using namespace std;
int main(){
    int a,c;
    cin>>a;
    for(int i=1;i<=a;i++){
		if(i*(a/i)==a&&i>=(a/i)){
			c++;
		}
	}
	cout<<c;
}