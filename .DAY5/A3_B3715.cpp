#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        bool flag = true;
        for (ll i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                if (!flag) cout << ' ';
				printf("%lld",i);
                flag = false;
                n /= i;
            }
        }
        if (n > 1) {
            if (!flag) cout << ' ';
			printf("%lld",n);

        }
		printf("\n");
    }
    return 0;
}
