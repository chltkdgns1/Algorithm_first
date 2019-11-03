#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v[1001];
int deep[1001], par[1001][11], dp[1001][11];
bool visit[1001];
void dfs(int s, int d) {
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i].first;
		if (!visit[y]) {
			deep[y] = d + 1;
			dp[y][0] = v[s][i].second;
			par[y][0] = s;
			dfs(y, d + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, d; cin >> a >> d;
	for (int i = 0; i < a - 1; i++) {
		int x, y, z; cin >> x >> y >> z;
		v[x].push_back({ y,z });
		v[y].push_back({ x,z });
	}
	dfs(1, 0);
	for (int k = 1; k <= 10; k++) {
		for (int i = 1; i <= a; i++) {
			int d = par[i][k - 1];
			par[i][k] = par[d][k - 1];
			dp[i][k] = dp[i][k - 1] + dp[d][k - 1];
		}
	}
	while (d--) {
		int a, b; cin >> a >> b;
		if (deep[a] < deep[b]) swap(a, b);
		int s = 0;
		for (int i = 10; i >= 0; i--) {
			if (deep[a] - deep[b] >= (1 << i)) {
				s += dp[a][i];
				a = par[a][i];
			}
		}
		if (a == b) cout << s << "\n";
		else {
			for (int i = 10; i >= 0; i--) {
				if (par[a][i] != par[b][i]) {
					s += (dp[a][i] + dp[b][i]);
					a = par[a][i];
					b = par[b][i];
				}
			}
			s += dp[a][0] + dp[b][0];
			cout << s << "\n";
		}
	}
}