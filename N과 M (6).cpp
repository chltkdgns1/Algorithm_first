#include <iostream>
#include <algorithm>
using namespace std;
int a[10], d[10], n, m;
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < idx; i++) {
			if (d[i]) cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	if (idx == n) return;
	d[idx] = 1;
	dfs(idx + 1, cnt + 1);
	d[idx] = 0;
	dfs(idx + 1, cnt);
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	dfs(0, 0);
}