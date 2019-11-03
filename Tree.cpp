#include <iostream>
#include <vector>
using namespace std;
vector <int> v[1001];
bool visit[1001];
bool dfs(int s,int par) {
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (par == y) continue;
		if (visit[y]) return false;
		if (!visit[y]) {
			if (!dfs(y,s)) return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		bool ch = dfs(1, -1);
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				ch = 0; break;
			}
		}
		if (!ch) cout << "graph" << "\n";
		else cout << "tree" << "\n";
		for (int i = 1; i <= n; i++) v[i].clear(), visit[i] = 0;
	}
}