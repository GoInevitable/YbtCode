#include<bits/stdc++.h>
using namespace std;
int main(){
	int g, s, b;
	for(int i = 100; i <= 999; i++)
	{
		g = i/100;
		s = i/10%10;
		b = i%10;	
		if(g*g*g+s*s*s+b*b*b == i){
            cout << i << endl;
        }
	}
	return 0;
}
