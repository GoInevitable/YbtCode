#include <iostream>
using namespace std;
string s1,s2;
int main()
{
	cin >> s1 >> s2;
	if(s1.size()<s2.size())
		swap(s1,s2);
	s1=s1+s1;
	if(s1.find(s2)!=s1.npos)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}