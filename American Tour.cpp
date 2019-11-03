#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 987654321	
using namespace std;
int d[1001];
int store[1001][1001];
bool visit[1001];
vector <pair<int, int>> v[1001];
int n, m;
bool check;
void dikstra(int s) {
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[s] = 0;
	priority_queue <pair<int, int>> q;
	q.push({ 0,s });

	while (!q.empty()) {
		int cost = -q.top().first;
		int e = q.top().second;
		q.pop();
		for (int i = 0; i < v[e].size(); i++) {
			int next = v[e][i].first;
			int price = v[e][i].second + cost;
			if (store[e][next] == 2 && store[next][e] == 2 && !check) continue;
			if (d[next] > price) {
				d[next] = price;
				q.push({ -price,next });
			}
		}
	}
}
void deleteTrunkLine(int e) { // 1 to 2 line delete
	queue <int> q;
	visit[e] = 1;
	q.push(e);
	while (!q.empty()) {
		int w = q.front();
		q.pop();
		for (int i = 0; i < v[w].size(); i++) {
			int next = v[w][i].first;
			int cost = v[w][i].second;
			if (d[next] + cost == d[w] && !visit[next]) {
				visit[next] = 1;
				store[w][next]++, store[next][w]++;
				q.push(next);
			}
		}
	}
	memset(visit, 0, sizeof(visit));
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	int a = 0, b = 0;
	dikstra(1);
	deleteTrunkLine(2);
	dikstra(2);
	deleteTrunkLine(n);

	dikstra(1);
	a += d[2];
	check = 1;
	dikstra(2);
	a += d[n];
	dikstra(1);
	b += d[2];
	check = 0;
	dikstra(2);
	b += d[n];
	cout << min(a, b) << "\n";
}