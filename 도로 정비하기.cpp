#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> gph[4001];
int num[4001], cnt, grpn[4001];
bool com[4001];
stack<int> stk;
vector<vector<int> > grp;
int f(int now) {
	num[now] = ++cnt;
	stk.push(now);
	int ret = num[now];
	for (int nxt : gph[now]) {
		if (num[nxt] == 0)
			ret = min(ret, f(nxt));
		else if (!com[nxt])
			ret = min(ret, num[nxt]);
	}
	if (ret == num[now]) {
		vector<int> tmpv;
		while (true) {
			int tmp = stk.top();
			stk.pop();

			grpn[tmp] = grp.size() + 1;
			com[tmp] = true;
			tmpv.push_back(tmp);

			if (tmp == now)
				break;
		}
		grp.push_back(tmpv);
	}
	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i <= 4000; ++i) {
			gph[i].clear();
			num[i] = 0;
			grpn[i] = 0;
			com[i] = false;
		}
		cnt = 0;
		grp.clear();
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		while (k--) {
			pair<int, int> u, v;
			scanf("%d %d %d %d", &u.first, &u.second, &v.first, &v.second);
			int a, b, c, d, na, nb, nc, nd;
			if (u == v)
				continue;
			if (u.first < v.first) {
				a = u.second;
				na = m + u.second;
				c = v.second;
				nc = m + v.second;
			}
			else {
				a = m + u.second;
				na = u.second;
				c = m + v.second;
				nc = v.second;
			}
			if (u.second < v.second) {
				b = 2000 + v.first;
				nb = 2000 + n + v.first;
				d = 2000 + u.first;
				nd = 2000 + n + u.first;
			}
			else {
				b = 2000 + n + v.first;
				nb = 2000 + v.first;
				d = 2000 + n + u.first;
				nd = 2000 + u.first;
			}
			gph[na].push_back(c);
			gph[na].push_back(d);
			gph[nb].push_back(c);
			gph[nb].push_back(d);
			gph[nc].push_back(a);
			gph[nc].push_back(b);
			gph[nd].push_back(a);
			gph[nd].push_back(b);
		}
		for (int i = 1; i <= m * 2; ++i)
			if (num[i] == 0)
				f(i);
		for (int i = 2001; i <= 2000 + n * 2; ++i)
			if (num[i] == 0)
				f(i);
		bool can = true;
		for (int i = 1; i <= m; ++i)
			if (grpn[i] == grpn[m + i])
				can = false;
		for (int i = 2001; i <= 2000 + n; ++i)
			if (grpn[i] == grpn[n + i])
				can = false;
		printf("%s\n", can ? "Yes" : "No");
	}
	return 0;
}
