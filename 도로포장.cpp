#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector <pair<int,int>> v[10001];
long long dis[12345][25];
int n, m, k;
void dijkstra(int s) {
	dis[s][k] = 0;
	priority_queue <pair<long long ,pair<int,int>>> q;
	q.push({ 0,{s,k } });   
	while (!q.empty()) {
		int load = q.top().second.second; // 포장 도로의 개수
		int cur = q.top().second.first; // 방향
		long long cost = -q.top().first; // 비용
		q.pop(); 

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first; // 다음 노드를 번호
			long long next_cost = v[cur][i].second; // 다음 노드로 갈 비용

			if (load > 0) {
				if (dis[next][load - 1] > cost) {
					dis[next][load - 1] = cost;
					q.push({ -cost ,{next,load - 1} });
				}
			}
			if (dis[next][load] > cost + next_cost) {
				dis[next][load] = cost + next_cost;
				q.push({ -dis[next][load],{next,load } });
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		for(int j=0;j<=20;j++) dis[i][j] = 1e15;
	}
	dijkstra(1);
	long long min1 = 1e15;
	for (int i = 0; i <= k; i++) {
		if (min1 > dis[n][i]) min1 = dis[n][i];
	}
	cout << min1 << "\n";
}