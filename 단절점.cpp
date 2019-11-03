#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
vector <int> v[10001], e;
int d[10001], cnt;
bool ch[10001];
int dfs(int s, bool rot) {
	d[s] = ++cnt;
	int cc = d[s], child = 0;
	for (auto a : v[s]) {
		if (d[a]) {
			cc = min(cc, d[a]);
			continue;
		}
		child++;
		int t = dfs(a, 0);
		if (!rot && t >= d[s]) ch[s] = 1;
		cc = min(cc, t);
	}
	if (rot) ch[s] = (child >= 2);

	return cc;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!d[i]) dfs(i, 1);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (ch[i]) cnt++;
	}
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++) {
		if (ch[i]) cout << i << " ";
	}
	system("pause");
}