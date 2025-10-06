#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node {
	int v;
	int idx;
};
queue<node> q[N];
vector<int> qlist;
int a[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[0] = -1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) q[++cnt].push({a[i], i});
		else q[cnt].push({a[i], i});
	}
	for (int i = 1; i <= cnt; i++) qlist.push_back(i);

	while (!qlist.empty()) {
		int i = 0;
		while (i < qlist.size()) {
			int j = qlist[i];
			cout << q[j].front().idx << " ", q[j].pop();
			//printf("%d %d", q[j].front().idx, q[j].pop());
			if (q[j].empty()) {
				qlist.erase(qlist.begin() + i);
			} else {
				if (i != 0) {
					int f = qlist[i - 1];
					if (q[f].front().v == q[j].front().v) {
						while (!q[j].empty()) q[f].push(q[j].front()), q[j].pop();
						qlist.erase(qlist.begin() + i);
					} else  i++;
				} else i++;
			}
		}
		cout << endl;
	}
}

