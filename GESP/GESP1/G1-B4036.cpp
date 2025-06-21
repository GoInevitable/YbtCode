#include <cstdio>
using namespace std;
int a[100001];

int main() {

    //ios::sync_with_stdio(false);
    //cin.tie(0);
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        int t = a[i];
        int sum = 0;
        while (t != 0) {
            sum += t % 10;
            t /= 10;
        }
        printf("%s\n", (sum % 7 != 0) ? "No" : "Yes");
    }
    return 0;
}