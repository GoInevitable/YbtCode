#include <iostream>
using namespace std;
int main() {
    for (int x = 0; x <= 14; ++x) {
        int a = 100 - 7 * x;
        if (a < 0 || a % 4 != 0) {
            continue;
        }
        int y = a / 4;
        int z = 100 - x - y;
        if (z >= 0 && z % 3 == 0) {
            cout << x << " " << y << " " << z << endl;
        }
    }
    return 0;
}