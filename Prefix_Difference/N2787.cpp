#include <bits/stdc++.h>
using namespace std;
long long a[1000001], b[1000001];
int main()
{
    long long n, k, i, max = 0, sum = 0;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        b[i] = a[i] + b[i - 1];
    }
    for (i = 1; i <= n - k + 1; i++)
    {
        if (max < b[i + k - 1] - b[i - 1]){
            max = b[i + k - 1] - b[i - 1];
        } 
    }
    printf("%ld", sum - max);
    return 0;
}