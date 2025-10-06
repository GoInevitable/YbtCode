#include <bits/stdc++.h>
using namespace std;
double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main()
{
    double x1, y1, x2, y2, x3, y3, a, b, c;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    a = dis(x1, y1, x2, y2);
    b = dis(x2, y2, x3, y3);
    c = dis(x1, y1, x3, y3);
    double p = (a + b + c) / 2.0;
    printf("%.2f", sqrt(p * (p - a) * (p - b) * (p - c)));

    return 0;
}