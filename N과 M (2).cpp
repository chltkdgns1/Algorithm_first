#include <iostream>
using namespace std;
int d[10];
int n, m;
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= n; i++) {
			if (d[i]) cout << i << " ";
		}
		cout << "\n";
		return;
	}
	if (idx > n) return;
	d[idx] = 1;
	dfs(idx + 1, cnt + 1);
	d[idx] = 0;
	dfs(idx + 1, cnt);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	dfs(1, 0);
}