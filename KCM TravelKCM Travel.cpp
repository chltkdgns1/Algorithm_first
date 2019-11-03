#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
class Data {
public:
	int t, cost, dis;
	Data(int b,int c,int d) : t(b),cost(c),dis(d){}
};
vector <Data> v[101];
int d[101][10001];
void dikstra(int s,int n,int m) {
	for (int i = 1; i <= n; i++)
		fill(d[i], d[i] + m + 1, INF);
	d[s][0] = 0;
	priority_queue <pair<int,pair<int,int>>> q;
	q.push({ 0,{s,0} });
	while (!q.empty()) {
		int dis = -q.top().first; 
		int node = q.top().second.first;   
		int cost = q.top().second.second; 
		q.pop();
		if (d[node][cost] < dis) continue;
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i].t;
			int c = v[node][i].cost + cost;
			int load = v[node][i].dis + dis;
			if (c <= m && d[next][c] > load) {
				for(int i = c + 1;i<=m; ++i){
					if (d[next][i] <= load) break;
					d[next][i] = load;
				}
				d[next][c] = load;
				q.push({ -load,{next,c} });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			v[a].push_back(Data(b, c, d));
		}
		dikstra(1, n, m);
		int max = INF;
		for (int i = 1; i <= m; i++) {
			if (d[n][i] && d[n][i] != INF) {
				max = max > d[n][i] ? d[n][i] : max;
			}
		}
		for (int i = 1; i <= n; i++) v[i].clear();
		if (max == INF) cout << "Poor KCM\n";
		else cout << max << "\n";
	}
}