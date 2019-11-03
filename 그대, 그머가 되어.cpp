#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> v[1001];
bool visit[1001];
int to, from;
void solve(int s) {
	visit[s] = 1;
	queue <pair<int, int>> q;
	q.push({ s,0 });
	while (!q.empty()) {
		int n = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (n == to) {
			cout << cost << "\n";
			return;
		}
		for (auto a : v[n]) {
			if (!visit[a]) {
				visit[a] = 1;
				q.push({ a,cost + 1 });
			}
		}
	}
	cout << -1 << "\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> from >> to;
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve(from);
}