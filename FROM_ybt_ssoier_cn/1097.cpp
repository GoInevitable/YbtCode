#include <iostream>
using namespace std;

int main()
{
    int h, w, s;
    char c;
    cin >> h >> w >> c >> s;

    if (s)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cout << c;
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < h; i++)
        {
            if (i == 0 || i == h - 1)
            {
                for (int j = 0; j < w; j++)
                {
                    cout << c;
                }
                cout << endl;
            }
            else
            {
                cout << c;
                for (int j = 1; j < w - 1; j++)
                {
                    cout << ' ';
                }
                cout << c << endl;
            }
        }
    }
    return 0;
}