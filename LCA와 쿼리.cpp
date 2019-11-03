#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int d[100001], par[100001][18],  deep[100001];
vector <int> v[100001];
void dfs(int s, int p) {
	for (auto a : v[s]) {
		if (a == p) continue;
		par[a][0] = s;
		deep[a] = deep[s] + 1;
		dfs(a, s);
	}
}

int lca(int a, int b) {
	if (deep[a] < deep[b]) swap(a, b);
	for (int k = 16; k >= 0; k--) {
		if (deep[a] - deep[b] >= (1 << k)) {
			a = par[a][k];
		}
	}

	if (a != b) {
		for (int k = 16; k >= 0; k--) {
			if (par[a][k] != par[b][k]) {
				a = par[a][k];
				b = par[b][k];
			}
		}
		return a = par[a][0];
	}
	else return a;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,a,b; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1, -1);

	for (int i = 0; i <= 16; i++) {
		for (int k = 1; k <= n; k++) {
			int d = par[k][i];
			par[k][i + 1] = par[d][i];
		}
	}

	int m; cin >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		int q = lca(a, b), w = lca(b, c), e = lca(a, c);
		if (deep[q] >= deep[w] && deep[q] >= deep[e]) cout << q << "\n";
		else if (deep[w] >= deep[q] && deep[w] >= deep[e]) cout << w << "\n";
		else if (deep[e] >= deep[q] && deep[e] >= deep[w]) cout << e << "\n";
	}
}