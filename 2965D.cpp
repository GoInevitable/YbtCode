#include <iostream>
using namespace std;
int a[1001][1001];

int main() {
    int n, h, k = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        int k2 = k;
        for(int j=0; j <= k2; j++){
            if(a[j][0] == 0){
                a[j][0]++;
                a[j][1] = h;
                k++;
                break;
            } else if(a[j][a[j][0]] > h){
                a[j][0]++;
                a[j][a[j][0]] = h;
                break;
            }
        }
    }
    cout << k << endl;
    for (int i = 0; i < k; ++i) {
        if (a[i][0] == 0) continue;
        cout << i+1 << ":";
        for (int j = 1; j <= a[i][0]; ++j) {
            cout<<a[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}
//1375: 【提高】拦截导弹方案求解 https://noicsp.com/problem.php?id=1375