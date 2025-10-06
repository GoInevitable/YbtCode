#include <bits/stdc++.h>
using namespace std;
#define File(p) freopen (p".in","r",stdin); freopen (p".out","w",stdout)
typedef pair<int, int> PII;

const int N = 2e6 + 10;
char op[N];
int d[N];
int l[N], r[N];
int dn = 0, pn = 1e6;
PII ans[N];
stack<int> p, v;
void build() {
    int pp = p.top();
    p.pop();
    int a = v.top();
    v.pop();
    int b = v.top();
    v.pop();
    l[pp] = b, r[pp] = a;
    v.push(pp);
}
int encode(string s) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == '0' || s[i] == '1') {
            d[++dn] = s[i] - '0';
            v.push(dn);
        } else if (s[i] == '(') {
            op[++pn] = s[i];
            p.push(pn);
        } else if (s[i] == ')') {
            while (op[p.top()] != '(') build();
            p.pop();
        } else if (s[i] == '&') {
            while (!p.empty() && op[p.top()] == '&') build();
            op[++pn] = s[i];
            p.push(pn);
        } else { //s[i]=='|'
            while (!p.empty() && op[p.top()] != '(') build();
            op[++pn] = s[i];
            p.push(pn);
        }
    }
    while (!p.empty()) build();
    return    v.top();
}
int res1 = 0, res2 = 0;
int dfs(int u) {
    if (u <= 1e6) return d[u];
    bool dl = dfs(l[u]);
    if (op[u] == '&' && dl == 0) {
        res1++;
        return 0;
    } else if (op[u] == '|' && dl == 1) {
        res2++;
        return 1;
    } else {
        if (op[u] == '&') return dl & dfs(r[u]);
        else return dl | dfs(r[u]);
    }
}
int main() {
//    freopen("expr4.in", "r", stdin);
    string s;
    cin >> s;
    int root = encode(s);
    cout << dfs(root) << endl;
    cout << res1 << " " << res2 << endl;
    return 0;
}
