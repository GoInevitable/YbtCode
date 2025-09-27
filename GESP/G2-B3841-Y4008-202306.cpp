#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        int t = n;
        int l = 0;
        while (t) {
            l++;
            t /= 10;
        }
        t = n;
        int sum = 0;
        while (t) {
            int d = t % 10;
            int p = 1;
            for (int j = 0; j < l; j++) {
                p *= d;
            }
            sum += p;
            t /= 10;
        }
        if (sum == n) {
            cout << 'T' << endl;
        } else {
            cout << 'F' << endl;
        }
    }
    return 0;
}
//B3841 [GESP202306 二级] 自幂数判断
//https://www.luogu.com.cn/problem/B3841
//http://ybt.ssoier.cn:8088/problem_show.php?pid=4008