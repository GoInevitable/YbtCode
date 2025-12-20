/**
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @problem //https://www.luogu.com.cn/problem/B4007 B4007 [GESP202406 二级] 计数
 * @license MIT
 */
#include<iostream>
using namespace std;
int main() {
	int n, ans = 0,k;
	scanf("%d%d", &n,&k);
	for (int i = 1; i <= n; i++) {
		int t=i;
		while(t!=0){
			if(t%10==k){
				ans++;
			}
			t/=10;
		}
	}
	cout<<ans;
	return 0;
}
