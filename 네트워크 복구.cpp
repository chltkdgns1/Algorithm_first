#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector <pair<int, int>> v[1001];
int d[1001];
int n, m;
void dijkstra(int s) {
	d[s] = 0;
	vector <pair<int, int>> t;
	priority_queue <pair<int, pair<int, int>>> pq;
	pq.push({ 0,{ s,0 } });
	while (!pq.empty()) {
		int cur = pq.top().second.first;
		int cost = -pq.top().first;
		int par = pq.top().second.second;
		pq.pop();
		if (d[cur] < cost) continue;
		if (par) {
			t.push_back({ cur,par });
		}
		for (int i = 0; i < v[cur].size(); i++) {
			int next_cur = v[cur][i].first;
			int next_dis = v[cur][i].second + cost;
			if (d[next_cur] > next_dis) {
				d[next_cur] = next_dis;
				pq.push({ -next_dis,{next_cur,cur} });
			}
		}
	}
	cout << t.size() << "\n";
	for (int i = 0; i < t.size(); i++) {
		cout << t[i].first << " " << t[i].second << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) d[i] = 1e9;
	dijkstra(1);
}