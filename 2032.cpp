#include<bits/stdc++.h>
using namespace std;
void split(int n)
{
	for(int i = 2; i <= n; ++i)
	{
		if(n % i == 0)
		{
			cout << i;
			if(n/i > 1)
			{
				cout << '*';
				split(n/i);
			}
			break;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	cout << n << '='; 
	split(n);
	return 0;
}
