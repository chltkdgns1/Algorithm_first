#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector <int> v[20001];
int visit[20001], c = 1, cnt = 1;
int d[20001];
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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[n - a].push_back(n + b);
		v[n - b].push_back(n + a);
	}
	for (int i = 0; i <= 2 * n; i++) {
		if (!visit[i]) dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		if (d[n - i] == d[n + i]) {
			cout << 0 << "\n";
			return 0;
		}
	}
	cout << 1 << "\n";
}