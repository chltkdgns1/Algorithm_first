#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class Data {
public:
	int a, b, c;
};
vector <Data> v, r;
vector <pair<int, int>> e[200001];
int d[200001], dp[200001][18], par[200001][18], deep[200001];
void dfs(int s, int p) {
	for (auto a : e[s]) {
		if (a.first == p) continue;
		dp[a.first][0] = a.second;
		par[a.first][0] = s;
		deep[a.first] = deep[s] + 1;
		dfs(a.first, s);
	}
}
int find(int x) {
	if (x == d[x]) return x;
	return d[x] = find(d[x]);
}
bool _union(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	d[b] = a;
	return true;
}
bool cmp(Data &a, Data &b) {
	return a.c < b.c;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		r.push_back({ a,b,c});
		v.push_back({ a,b,c });
	}
	for (int i = 1; i <= n; i++) d[i] = i;
	sort(v.begin(), v.end(), cmp);
	ll res = 0;
	for (int i = 0; i < v.size(); i++) {
		int a = v[i].a, b = v[i].b;
		if (_union(a, b)) {
			res += v[i].c;
			e[a].push_back({ b,v[i].c });
			e[b].push_back({ a,v[i].c });
		}
	}
	dfs(1, -1);
	for (int i = 0; i <= 16; i++) {
		for (int k = 1; k <= n; k++) {
			int d = par[k][i];
			par[k][i + 1] = par[d][i];
			dp[k][i + 1] = max(dp[k][i], dp[d][i]);
		}
	}
	for (auto a : r) {
		int c = a.a, d = a.b;
		int t = 0;
		if (deep[c] < deep[d]) swap(c, d);
		for (int k = 17; k >= 0; k--) {
			if (deep[c] - deep[d] >= (1 << k)) {
				t = max(t, dp[c][k]);
				c = par[c][k];
			}
		}
		if (c != d) {
			for (int k = 17; k >= 0; k--) {
				if (par[c][k] != par[d][k]) {
					t = max(t, dp[c][k]);
					t = max(t, dp[d][k]);
					c = par[c][k], d = par[d][k];
				}
			}
			t = max(t, dp[c][0]);
			t = max(t, dp[d][0]);
		}
		cout << res - t + a.c << "\n";
	}
}