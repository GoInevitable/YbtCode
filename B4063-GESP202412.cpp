#include <iostream>
using namespace std;
int main()
{
    int n, x, j = 0, o = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x % 2 == 0)
        {
            o++;
        }
        else
        {
            j++;
        }
    }
    printf("%d %d", j, o);
    return 0;
}