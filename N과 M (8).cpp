#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[10], d[10];
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < idx; i++) {
			cout << d[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!idx) {
			d[idx] = arr[i];
			dfs(idx + 1, cnt + 1);
			d[idx] = 0;
		}
		else {
			if (d[idx - 1] <= arr[i]) {
				d[idx] = arr[i];
				dfs(idx + 1, cnt + 1);
				d[idx] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs(0, 0);
}