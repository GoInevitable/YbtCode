#include <cstdio>

int main() {
    int m;
    scanf("%d", &m);
    
    while (m--) {
        int n;
        scanf("%d", &n);
        int t = n, p = 0, sum = 0;
        while (t) {
            t /= 10;
            p++;
        }
        t = n;
        while (t) {
            int d = t % 10;
            int p = 1;
            for (int i = 0; i < p; i++) {
                p *= d;
            }
            sum += p;
            t /= 10;
        }
        if (sum == n) {
            printf("T\n");
        } else {
            printf("F\n");
        }
    }
    return 0;
}