#include <iostream>
using namespace std;
int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    if (l / n == r / n)
        cout << r % n;
    else
        cout << n - 1;
    return 0;
}
