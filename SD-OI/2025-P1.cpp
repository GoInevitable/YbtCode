#include <bits/stdc++.h>
#include <string>
using namespace std;
string s1;
string ans;
int solve1(int n)
{
    for (int i = n + 1; i < s1.size(); i++)
    {
        
    }
}
int solve2(int n)
{
    int m =solve1(n);

}
int main()
{

    cin >> s1;
    for (int i = 0; i <= s1.size() - 1; i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            ans += s1[i];
        }
        else
        {
            solve2(i);
        }
    }
    return 0;
}