#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int d[10],n, m;
bool check[10];
void dfs(int index,int cnt) {
	if (m == cnt) {
		for (int i = 0; i < index; i++) {
			if (d[i]) {
				cout << d[i] << " ";
			}
		}
		cout << "\n";
		return;
	}
	if (index == n) return;
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = 1;
			d[index] = arr[i];
			dfs(index + 1, cnt + 1);
			d[index] = 0;
			check[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs(0, 0);
}