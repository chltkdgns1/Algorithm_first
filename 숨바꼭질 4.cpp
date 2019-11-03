#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

bool visit[100001];
int parent[100001];
int n, m;
void bfs() {
	visit[n] = 1;
	parent[n] = n;
	queue <pair<int, int>> q;
	q.push({ n,0 });
	while (!q.empty()) {
		int s = q.front().first;
		int c = q.front().second;
		if (s == m) {
			vector <int> v;
			cout << c << "\n";
			while (parent[s] != s) {
				v.push_back(s);
				s = parent[s];
			}
			v.push_back(n);
			for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
		}
		q.pop();
		if (2 * s <= 100000 && !visit[s * 2]) {
			visit[s * 2] = 1;
			parent[s * 2] = s;
			q.push({ s * 2,c + 1 });
		}
		if (s - 1 >= 0 && !visit[s - 1]) {
			visit[s - 1] = 1;
			parent[s - 1] = s;
			q.push({ s - 1,c + 1 });
		}
		if (s + 1 <= 100000 && !visit[s + 1]) {
			visit[s + 1] = 1;
			parent[s + 1] = s;
			q.push({ s + 1,c + 1 });
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	 cin >> n >> m;
	 bfs();
}