#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1000001;

int no[MAXN];

int main() {
    memset(no, 0, sizeof(no));
    no[1] = 0;
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            no[y] = no[x]; 
            no[x] = y;           
        } else if (op == 2) {
            int x;
            cin >> x;
            cout << no[x] << endl;
        } else if (op == 3) {
            int x;
            cin >> x;
            int t = no[x];
            no[x] = no[t];
        }
    }
    return 0;
}
