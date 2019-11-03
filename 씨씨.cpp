#include <iostream>
#define INF 987654321
using namespace std;
int dis[201][201];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int k = 1; k <= n; k++) {
		dis[i][k] = i == k ? 0 : INF;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		dis[a][b] = c;
		dis[b][a] = c;
	}
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			for (int c = 1; c <= n; c++) {
				if (dis[b][a] + dis[a][c] < dis[b][c]) {
					dis[b][c] = dis[b][a] + dis[a][c];
				}
			}
		}
	}
	int c; cin >> c;
	while (c--) {
		int a, b; cin >> a >> b;
		if (dis[a][b] == INF) cout << -1 << "\n";
		else cout << dis[a][b] << "\n";
	}
}