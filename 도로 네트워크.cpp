#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v[100001];
int deep[100001], parent[100001][18];// ±íÀÌ, ºÎ¸ð
int dis1[100001][18],dis2[100001][18];
bool visit[100001];
void dfs(int s, int deeps) {
	visit[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i].first;
		if (!visit[y]) {
			parent[y][0] = s;
			deep[y] = deeps;
			dis1[y][0] = dis2[y][0] = v[s][i].second;
			dfs(y, deeps + 1);
		}
	}
}
void f(int n) {
	for (int k = 1; k <= 17; k++) {
		for (int i = 1; i <= n; i++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
			dis1[i][k] = min(dis1[parent[i][k - 1]][k - 1], dis1[i][k - 1]);
			dis2[i][k] = max(dis2[parent[i][k - 1]][k - 1], dis2[i][k - 1]);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 1);
	f(n);
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (deep[a] > deep[b]) swap(a, b);

		int ma = dis2[b][0], mi = dis1[b][0];
		for (int i = 17; i >= 0; i--) {
			if (deep[b] - deep[a] >= (1 << i)) {
				ma = max(ma, dis2[b][i]);
				mi = min(mi, dis1[b][i]);
				b = parent[b][i];
			}
		}

		if (a == b) cout << mi << " " << ma << "\n";
		else { 
			for (int i = 17; i >= 0; i--) {
				if (parent[a][i] != parent[b][i]) {
					ma = max(max(ma, dis2[b][i]), dis2[a][i]);
					mi = min(min(mi, dis1[b][i]), dis1[a][i]);
					a = parent[a][i];
					b = parent[b][i];
				}
			}
			ma = max(max(ma, dis2[b][0]), dis2[a][0]);
			mi = min(min(mi, dis1[b][0]), dis1[a][0]);
			cout << mi << " " << ma << "\n";
		}
	}
}