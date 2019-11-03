#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
vector <int> v[100001];
stack <int> st;
bool visit[100001];
void dfs(int s) {
	visit[s] = 1;
	for (auto a : v[s]) {
		if (!visit[a]) dfs(a);
	}
	st.push(s);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, a, b; cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a >> b;
			v[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) dfs(i);
		}
		memset(visit, 0, sizeof(visit));
		int cnt = 0;
		while (!st.empty()) {
			int s = st.top();
			st.pop();
			if (visit[s]) continue;
			dfs(s);
			cnt++;
		}
		cout << cnt << "\n";
		for (int i = 1; i <= n; i++) v[i].clear(), visit[i] = 0;
	}
}