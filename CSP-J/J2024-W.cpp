#include <bits/stdc++.h>
using namespace std;
long long n;
void solve(int n){
    if (n == 1)
            cout << -1;
        else if (n == 2)
            cout << 1;
        else if (n == 3)
            cout << 7;
        else if (n == 4)
            cout << 4;
        else if (n == 5)
            cout << 2;
        else if (n == 6)
            cout << 6;
        else if (n == 7)
            cout << 8;
        else if (n % 7 == 1)
        {
            cout << 10,n-=8;
        }
        else if (n % 7 == 2)
        {
            cout << 1,n-=2;
        }
        else if (n % 7 == 3)
        {
            if (n == 10)
                cout << 22,n-=10;
            else
            {
                cout << 200,n-=17;
            }
        }
        else if (n % 7 == 4)
        {
            cout << 20,n-=11;
        }
        else if (n % 7 == 5)
        {
            cout << 2,n-=5;
        }
        else if (n % 7 == 6)
        {
            cout << 6,n-=6;
        }
        for(int i= 1;i<=n/7;i++){
            cout<<8;
        }
        cout << endl;

    }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        solve(n);
    }    
    return 0;
}
