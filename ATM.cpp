#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> v[500001], e[500001], vv[500001];
int d[500001], rd[500001]; // rd 는 scc 사이클의 돌면서 수금한 돈
bool check[500001], rc[500001]; // 해당 점에 레스토랑이 있는지
int visit[500001];
stack <int> s;

void dfs(int u) {
	visit[u] = 1;
	for (auto a : v[u]) {
		if (!visit[a]) dfs(a);
	}
	s.push(u);
}

int solve(int s,int cnt){
	visit[s] = cnt;
	int cost = d[s];
	if (check[s]) rc[cnt] = 1;
	for (auto a : e[s]) {
		if (!visit[a]) cost += solve(a,cnt);
	}
	return cost;
}


int bfs(int s) {
	memset(visit, 0, sizeof(visit));
	priority_queue <pair<int, int>> q;
	q.push({rd[s],s});
	visit[s] = rd[s];

	int res = 0;
	while (!q.empty()) {
		
		int n = q.top().second;
		int cost = q.top().first;

		if (rc[n]) res = max(res, cost);
		
		q.pop();

		for (auto a : vv[n]) {
			if (cost + rd[a] > visit[a]) {
				q.push({ cost + rd[a],a});
				visit[a] = cost + rd[a];
			}
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a, b; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 0; i < n; i++) cin >> d[i + 1];
	
	int st, e;
	cin >> st >> e;
	for (int i = 0; i < e; i++) {
		cin >> a; check[a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if(!visit[i]) dfs(i);
	}

	memset(visit, 0, sizeof(visit));

	int cnt = 1; // 새로 생긴 사이클의 정점
	while (!s.empty()) {
		int t = s.top();
		s.pop();

		if (visit[t]) continue;

		rd[cnt] = solve(t,cnt);
		cnt++;
	}

	for (int i = 1; i <= n; i++) {
		for (auto a : v[i]) {
			if (visit[a] == visit[i]) continue;
			int c = visit[i], d = visit[a];
			vv[c].push_back(d);
		}
	}

	cout << bfs(visit[st]) << "\n";
}