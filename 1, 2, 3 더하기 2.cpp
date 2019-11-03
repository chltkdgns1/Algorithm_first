#include <iostream>
using namespace std;

int cnt;
int arr[3] = { 1,2,3 };
int d[100000];
int n, k;
bool dfs(int n, int index, int d_index) {
	if (n - arr[index] > 0) {
		d[d_index] = arr[index];
		for (int i = 0; i < 3; i++) {
			if (dfs(n - arr[index], i, d_index + 1) == true) {
				return true;
			}
		}
		d[d_index] = 0;
	}
	else if (!(n - arr[index])) {
		cnt++;
		d[d_index] = arr[index];
		if (cnt == k) {
			for (int i = 0; i <= d_index; i++) {
				if (i == d_index) cout << d[i] << "\n";
				else cout << d[i] << "+";
			}
			return true;
		}
		d[d_index] = 0;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < 3; i++) {
		if (dfs(n, i, 0) == true) break;
	}
	if (cnt < k) cout << -1 << "\n";
}