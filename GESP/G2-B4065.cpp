#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        int cnt = 0;
        while (x > 0) {
            cnt += x % 10;
            x /= 10;
        }
        if (cnt > sum) {
            sum = cnt;
        }
    }
    
    cout << sum << endl;
    return 0;
}//https://www.luogu.com.cn/problem/B4065 B4065 [GESP202412 二级] 数位和