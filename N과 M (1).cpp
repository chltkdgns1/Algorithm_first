#include <iostream>
using namespace std;
int d[12], n, m;
bool check[12];
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < idx; i++) {
			if (d[i]) cout << d[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = 1;
			d[idx] = i;
			dfs(idx + 1, cnt + 1);
			d[idx] = 0;
			check[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	dfs(0, 0);
	system("pause");
}