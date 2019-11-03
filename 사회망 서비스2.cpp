#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
bool visit[1000001];
int dp[1000001][2];
vector <int> e[1000001];
vector <int> v[1000001];
void dfs(int s) {
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!visit[y]) {
			e[s].push_back(y);
			dfs(y);
		}
	}
}
int solve(int s, bool check) {
	int &res = dp[s][check];
	if (res != -1) return res;
	if (check) {
		res = 1;
		for (int i = 0; i < e[s].size(); i++) {
			int y = e[s][i];
			res += min(solve(y, 1), solve(y, 0));
		}
	}
	else {
		res = 0;
		for (int i = 0; i < e[s].size(); i++) {
			int y = e[s][i];
			res += solve(y, 1);
		}
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	dfs(1);
	cout << min(solve(1, 0), solve(1, 1)) << "\n";
}