#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

vector <int> v[100001];
int deep[100001];
int parent[100001][18];
bool visit[100001];
void dfs(int s, int deeps) {
	deep[s] = deeps;
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!visit[y]) {
			parent[y][0] = s;
			dfs(y, deeps + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(parent, -1, sizeof(parent));
	dfs(1, 0);
	for (int i = 0; i < 18; i++) {
		for (int k = 1; k <= n; k++) {
			if (parent[k][i] != -1) {
				parent[k][i + 1] = parent[parent[k][i]][i];
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (deep[a] < deep[b]) swap(a, b);
		for (int i = 17; i >= 0; i--) {
			if (deep[a] - deep[b] >= (1 << i)) {
				a = parent[a][i];
			}
		}

		if (a != b) {
			for (int i = 17; i >= 0; i--) {
				if (parent[a][i] != -1 && parent[a][i] != parent[b][i]) {
					a = parent[a][i];
					b = parent[b][i];
				}
			}
			a = parent[a][0];
		}
		cout << a << "\n";
	}
}