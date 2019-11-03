#include <iostream>
using namespace std;
int n, m, f[501], map[501][501], a, b, cnt = 0;
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		map[a][b] = 1, map[b][a] = 1;
		if (a == 1) { f[b] = 1; }
		else if (b == 1) { f[a] = 1; }
	}
	for (int i = 2; i <= n; i++) {
		if (map[1][i] == 1) {
			for (int j = 2; j <= n; j++) {
				if (map[i][j] == 1) {
					f[j] = 1;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (f[i] == 1) { cnt++; }
	}
	cout << cnt << '\n';
	return 0;
}