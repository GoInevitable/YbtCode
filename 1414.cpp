#include <bits/stdc++.h>
using namespace std;

struct student
{
    int math, num;
    string name;
} stu[101];
bool cmp(student x, student y)
{
    if (x.math == y.math)
    {
        return x.num < y.num;
    }
    else
    {
        return x.math > y.math;
    }
}
int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].num >> stu[i].name >> stu[i].math;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << stu[i].num << ' ' << stu[i].name << ' ' << stu[i].math << ' ' << endl;
    }
    return 0;
}