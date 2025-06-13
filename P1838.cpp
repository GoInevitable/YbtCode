#include <bits/stdc++.h>
using namespace std;
int zhi(int n){
    int i = 2;
	cout << n << '=';
	bool flag = 1;
	while (n > 1)
	{
		if (n % i == 0)
		{
			if (flag)
			{
				flag = 0;
			}
			else
			{
				cout << '*';
			}
			cout << i;
			n /= i;
		}
		else
		{
			i++;
		}
	}
    cout<<endl;
	return 0;
}
int main()
{
	int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
        zhi(i);
	return 0;
}
//https://noicsp.com/problem.php?id=1838 