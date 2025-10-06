#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	long long c=__gcd(a, b);
	cout << c <<" "<< a*b/c;
	return 0;
}
