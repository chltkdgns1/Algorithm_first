#include <iostream>
using namespace std;
int d[10],n,m;
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < idx; i++) {
			cout << d[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		d[idx] = i;
		dfs(idx + 1, cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	dfs(0, 0);
}