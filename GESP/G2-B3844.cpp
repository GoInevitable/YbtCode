#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char a = 'A';
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", (char)((i + j) % 26 + 'A'));
        }
        printf("\n");
    }
    return 0;
}