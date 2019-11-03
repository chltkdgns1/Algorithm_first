#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> v[100001];
int deep[100001];
int parent[100001];
int dis[100001];
bool visit[100001];
void dfs(int s, int d) {
	visit[s] = 1;
	for (int i = 0; i< v[s].size(); i++) {
		int y = v[s][i].first;
		if (!visit[y]) {
			parent[y] = s;
			dis[y] = v[s][i].second;
			deep[y] = d + 1;
			dfs(y, d + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0);
	if (deep[a] < deep[b]) {
		swap(a, b);
	}
	int cost = 0;
	int max = 0;
	int t = deep[a] - deep[b];
	for (int i = 0; i < t; i++) {
		if (max < dis[a]) max = dis[a];
		cost += dis[a];
		a = parent[a];
	}
	if (a != b) {
		int t_a, t_b;
		while (a != b) {
			if (max < dis[a]) max = dis[a];
			if (max < dis[b]) max = dis[b];
			cost += (dis[a] + dis[b]);
			a = parent[a];
			b = parent[b];
		}
	}
	cout << cost - max<< "\n";
}