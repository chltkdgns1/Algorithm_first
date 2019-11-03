#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#define INF 10000000
using namespace std;

int d[10];
vector <pair<int,int>> v[10];

void distra(int node) {
	d[node] = 0;
	priority_queue <pair<int,int>> pq;
	pq.push({ node,0 });
	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i].first;
			int nextDistance = v[current][i].second + distance;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push({ next,-nextDistance });
			}
		}
	}	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int start_node;
	cin >> start_node;
	for (int i = 0; i < 10; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 1; i <= 6; i++) d[i] = INF;
	distra(start_node);
	for (int i = 1; i <= 6; i++) cout << d[i] << " ";
	cout << "\n";
	system("pause");
}