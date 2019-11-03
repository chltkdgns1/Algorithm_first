#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int d[10001], dp[10001][2];
bool res[10001];
vector <int> v[10001];
int dfs(int par, int s, bool check) {
	if (dp[s][check] != -1) return dp[s][check];

	if (check) dp[s][check] = d[s];
	else dp[s][check] = 0;

	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (y == par) continue;
		if (check) dp[s][check] += dfs(s, y, 0);
		else dp[s][check] += max(dfs(s, y, 0), dfs(s, y, 1));
	}
	return dp[s][check];
}
void trace(int par, int s, bool ch) {
	if (ch) {
		res[s] = 1;
		for (auto y : v[s]) {
			if (y == par) continue;
			trace(s, y, 0);
		}
	}
	else {
		for (auto y : v[s]) {
			if (y == par) continue;
			if (dp[y][1] >= dp[y][0]) trace(s, y, 1);
			else trace(s, y, 0);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int a = dfs(-1, 1, 0);
	int b = dfs(-1, 1, 1);
	bool ch = 0;
	if (a < b) ch = 1;
	trace(-1,1, ch);
	cout << max(a, b) << "\n";
	for (int i = 1; i <= n; i++) {
		if (res[i]) cout << i << " ";
	}
}