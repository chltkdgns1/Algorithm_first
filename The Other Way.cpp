#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define INF 987654321465464;
#define mod 1000000009
vector <pair<ll, ll>> v[100001];
ll d[100001], dp[100001];
int n, m, s, e;
void dikstra() {
	priority_queue <pair<ll, ll>> q;
	q.push({ 0,s });
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[s] = 0; dp[s] = 1;

	while (!q.empty()) {
		ll node = q.top().second;
		ll cost = -q.top().first;
		q.pop();

		if (d[node] < cost) continue;
		for (auto a : v[node]) {
			int n_a = a.first;
			int n_c = a.second;
			if (d[n_a] > cost + n_c) {
				dp[n_a] = dp[node] % mod;
				d[n_a] = cost + n_c;
				q.push({ -d[n_a],n_a });
			}
			else if (d[n_a] == cost + n_c) {
				dp[n_a] = (dp[n_a] + dp[node]) % mod;
			}
		}
	}
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
	dikstra();
	cout << dp[e] << "\n";
}
