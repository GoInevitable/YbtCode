#include<iostream>
using namespace std;
int main() {
	int r,h;
	cin>>h>>r;
	int t=20000/(3.14*r*r*h)+1;
	cout<<t;
	
	return 0;
}