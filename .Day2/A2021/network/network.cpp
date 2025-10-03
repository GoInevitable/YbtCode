#include <bits/stdc++.h>
using namespace std;
string sever[1001][2];
string op, ad;
int n, len;
bool check(string s)
{
    // 检查格式 a.b.c.d:e
    int dot = 0, colon = 0;
    for (char c : s)
    {
        if (c == '.')
            dot++;
        if (c == ':')
            colon++;
    }
    if (dot != 3 || colon != 1)
        return false;

    vector<string> parts;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, '.'))
    {
        parts.push_back(tmp);
        if (parts.size() == 4)
            break;
    }
    if (parts.size() != 4)
        return false;
    string last = parts[3];
    size_t pos = last.find(':');
    if (pos == string::npos)
        return false;
    string d = last.substr(0, pos);
    string e = last.substr(pos + 1);
    parts[3] = d;
    parts.push_back(e);
    if (parts.size() != 5)
        return false;

    // 检查每一段是否合法
    for (int i = 0; i < 4; i++)
    {
        if (parts[i].empty())
            return false;
        if (parts[i].size() > 1 && parts[i][0] == '0')
            return false;
        for (char c : parts[i])
            if (!isdigit(c))
                return false;
        int num = stoi(parts[i]);
        if (num < 0 || num > 255)
            return false;
    }
    if (parts[4].empty())
        return false;
    if (parts[4].size() > 1 && parts[4][0] == '0')
        return false;
    for (char c : parts[4])
        if (!isdigit(c))
            return false;
    int port = stoi(parts[4]);
    if (port < 0 || port > 65535)
        return false;
    return true;
}
bool check2(string s)
{
    for (int i = 0; i < len; i++)
    {
        if (sever[i][0] == s)
        {
            return false;
        }
    }
    return true;
}
int check3(string s)
{
    for (int i = 0; i < len; i++)
    {
        if (sever[i][0] == s)
        {
            return i;
        }
    }
}

int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> op >> ad;
        if (check(ad))
        {
            if (op[0] == 'S')
            {
                if (check2(ad))
                {
                    sever[len][0] = ad;
                    sever[len][1] = to_string(i); // 修正：编号应为字符串
                    len++;
                    cout << "OK" << endl;
                }
                else
                {
                    cout << "FAIL" << endl;
                }
            }
            else
            {
                if (!check2(ad))
                {
                    int idx = check3(ad);
                    if (idx != -1)
                        cout << sever[idx][1] << endl;
                    else
                        cout << "FAIL" << endl; // 理论上不会走到这里
                }
                else
                {
                    cout << "FAIL" << endl;
                }
            }
        }
        else
        {
            cout << "ERR" << endl;
        }
    }
    return 0;
}