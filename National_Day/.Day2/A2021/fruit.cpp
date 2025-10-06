#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N], idx;
vector<vector<int>> t(N, vector<int>());
int main() {


	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1){
			t[++idx].push_back(a[i]);
			t[++idx].push_back(i);
			
		} else {
			if (a[i] == a[i - 1]) t[idx].push_back(i);
			else t[++idx].push_back(i);
		}
	}

	int cnt = 0;
	while (cnt <= n) {
		//取水果
		for (int i = 1; i <= idx; i++) {
			cout << t[i][1] << " ";
			t[i].erase(t[i].begin()+1);
			cnt++;
		}
		cout << endl;


		
		
		
	for(int i=1;i<=idx;i++){
		if(t[i].size()==1){
			t.erase(t.begin()+i);
			idx--,i--;
		}else{
			if(t[i][0]==t[i-1][0]){
				int len=t[i].size;
				for(int i=1;i<len;i++){
					t[i-1].push_back(t[i][j]);
				}
				t.erase(t.begin()+i)
			}
		}
	}
	}
	return 0;
}
