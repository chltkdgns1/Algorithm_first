#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

#define INF 1000000009
vector <pair<int, int>> v[100001];
ll d[100001];
int n, m, s, e;

void dikstra(int s) {
	priority_queue <pair<int, int>> q;
	q.push({ 0,s });

	while (!q.empty()) {
		int node = q.top().second;
		int cost = -q.top().first;
		q.pop();
		for (auto a : v[node]) {
			int n_a = a.first;
			int n_c = a.second;
			if (d[n_a] > cost + n_c) {
				d[n_a] = cost + n_c;
				q.push({ -d[n_a],n_a });
			}
		}
	}
}

ll tracing(int r) {
	if (s == r) return 1;
	ll t = 0;
	for (auto a : v[r]) {
		int n_s = a.first;
		int n_c = a.second;
		if (d[n_s] + n_c == d[r]) {
			t = (t + tracing(n_s)) % INF;
		}
	}
	return t;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s >> e;
	int a, b, c;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) d[i] = INF;
	d[s] = 0;
	dikstra(s);
	cout << tracing(e) << "\n";
	system("pause");
}
