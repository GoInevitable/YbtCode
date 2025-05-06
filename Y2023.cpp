#include <bits/stdc++.h>
using namespace std;

int main() {
    int max = INT_MIN, min = INT_MAX, n = 0, x;
    double sum = 0;
    
    while (scanf("%d", &x) == 1) {
        sum += x;
        if (x > max) max = x;
        if (x < min) min = x;
        n++;
    }
    
    double a = sum / n;
    cout << min << " " << max << " ";
    cout << fixed << setprecision(3) << a << endl;
    
    return 0;
}