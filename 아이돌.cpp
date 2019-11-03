#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector <int> v[2001];
int visit[2001], c = 1, cnt = 1;
int d[2001];
stack <int> st;
int dfs(int s) {
	visit[s] = c++;
	int deep = visit[s];
	st.push(s);
	for (auto a : v[s]) {
		if (!visit[a]) deep = min(deep, dfs(a));
		else if (!d[a]) deep = min(deep, visit[a]);
	}
	if (deep == visit[s]) {
		while (1) {
			int t = st.top();
			st.pop();
			d[t] = cnt;
			if (s == t) break;
		}
		cnt++;
	}
	return deep;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	while (cin >> n >> m) {
		bool res = 1;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			v[n - a].push_back(n + b);
			v[n - b].push_back(n + a);
		}
		v[n - 1].push_back(n + 1);
		for (int i = 0; i <= 2 * n; i++) {
			if (!visit[i]) dfs(i);
		}
		for (int i = 1; i <= n; i++) {
			if (d[n - i] == d[n + i]) res = 0;
		}
		if (d[n - 1] == d[n + 1]) res = 0;
		if (res) cout << "yes" << "\n";
		else cout << "no" << "\n";
		for (int i = 0; i <= 2 * n; i++) v[i].clear(), visit[i] = 0, d[i] = 0;
		c = 1, cnt = 1;
	}
}