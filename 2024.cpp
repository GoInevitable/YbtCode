#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 1;
    cin >> n;
	for(int i = 0; i < n; i++){
        ans = (ans * 1992) % 100;
    }
 	cout << ans;
	return 0;
}
//http://ybt.ssoier.cn:8088/problem_show.php?pid=2024 2024：【例4.10】末两位数