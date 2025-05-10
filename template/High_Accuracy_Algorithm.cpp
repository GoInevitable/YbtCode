#include <bits/stdc++.h>
using namespace std; 
// 函数名称:add
// 函数参数:两个vector<int>
// 函数返回值:一个vector<int>
// 函数功能:返回输入的两个vector的和 
// 中文名称:高精度加法 
vector <int> add(vector<int> &A,vector<int> &B){
	if (A.size() < B.size()) return add(B,A); // 因为下面for循环用A.size()当条件，所以现在只能让A比B长
	vector<int> C;
	int t = 0;
	for(int i = 0;i < A.size();i++){
		t += A[i];
		if(i < B.size()) t += B[i]; // 判断B是否够长 
		C.push_back(t % 10);
		t /= 10;
	}
	if (t) C.push_back(t);
	return C;
}
 
// 应用部分
vector <int> A,B,C; // 请不要将这个定义放在函数上面 
string CA,CB;// 因为A、B过长，所以需要使用字符串读入
int main(){
    cin >> CA >> CB;
	// 别忘了是逆序读入 
	for (int i = CA.size() - 1;i >= 0;i--) A.push_back(CA[i] - '0');
	for (int i = CB.size() - 1;i >= 0;i--) B.push_back(CB[i] - '0');
	C = add(A,B);
	// 逆序输出 
	for (int i = C.size() - 1;i >= 0;i--) cout << C[i];
	cout << endl; 
    return 0;
}