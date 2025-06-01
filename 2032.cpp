#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, i = 2;
	cin >> n;
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
	return 0;
}
