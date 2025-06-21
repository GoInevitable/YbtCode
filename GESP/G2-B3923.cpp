#include <iostream>
using namespace std;

int main() {
    int a, b, m, n;
    cin >> a >> b >> m >> n;
    int ans = 0;
    if (n >= 1) {
        ans += a;
    }
    if (n >= 2) {
        ans += b;
    }
    int f1 = a, f2 = b;
    for (int i = 3; i <= n; i++) {
        int t = f1 + f2;
        
        if (t >= m) {
            ans += t;  
            break;        
        } else {
            ans += t;  
            f1 = f2;
            f2 = t;
        }
    }

    cout << ans << endl;
    return 0;
}//https://www.luogu.com.cn/problem/B3923 B3923 [GESP202312 二级] 小杨做题