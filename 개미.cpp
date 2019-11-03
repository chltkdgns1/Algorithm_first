#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int d[100001], par[100001][17], dp[100001][17], deep[100001];
vector <pair<int, int>> v[100001];
void dfs(int s, int p) {
	for (auto a : v[s]) {
		if (a.first == p) continue;
		par[a.first][0] = s;
		dp[a.first][0] = a.second;
		deep[a.first] = deep[s] + 1;
		dfs(a.first, s);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, -1);
	for (int i = 0; i <= 15; i++) {
		for (int k = 1; k <= n; k++) {
			int d = par[k][i];
			par[k][i + 1] = par[d][i];
			dp[k][i + 1] = dp[d][i] + dp[k][i];
		}
	}
	for (int i = 1; i <= n;i++) {
		int index = i;
		for (int k = 15; k >= 0; k--) {
			if (deep[index] - deep[1] >= (1 << k) && d[i] >= dp[index][k]) {
				d[i] -= dp[index][k];
				index = par[index][k];
			}
		}
		cout << index << "\n";
	}
}