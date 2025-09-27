#include <bits/stdc++.h>
#include <string>
using namespace std;
string s;
string ans;
int solve1(int n)
{
    for (int i = n + 1; i < s.size(); i++)
    {
        
    }
}
int solve2(int n)
{
    int m =solve1(n);

}
int main()
{

    cin >> s;
    for (int i = 0; i <= s.size() - 1; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += s[i];
        }
        else
        {
            solve2(i);
        }
    }
    return 0;
}