#include <iostream>
using namespace std;

bool a(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int n;
    cin >> n;
    int t = 0;
    for (int y = 1998; y < n; y++) {
        t += 365;
        if (a(y))
            t += 1;
    }
    if (a(n)){
        months[1] = 29;
    }
    int d = 0;
    int ans = 0;
    for (int m = 0; m < 12; m++) {
        int wd = (4 + (t + d + 12)) % 7;
        if (wd == 5)
            ans++;
        d += months[m];
    }
    cout << ans << endl;
    return 0;
}