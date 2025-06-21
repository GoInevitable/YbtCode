#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;

    while (n != 495) {
        cnt++;
        int a[3];
        a[0] = n % 10;      // 个位
        a[1] = (n / 10) % 10; // 十位
        a[2] = n / 100;     // 百位
        
        sort(a, a + 3);
        
        int min_n = a[0] * 100 + a[1] * 10 + a[2];
        int max_n = a[2] * 100 + a[1] * 10 + a[0];
        n = max_n - min_n;
    }

    cout << cnt << endl;
    return 0;
}//https://www.luogu.com.cn/problem/B3866 B3866 [GESP202309 二级] 数字黑洞