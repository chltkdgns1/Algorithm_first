#include <iostream>
using namespace std;

int arr[101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <=n; i++) arr[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		int t = arr[a];
		arr[a] = arr[b];
		arr[b] = t;
	}
	for (int i = 1; i <=n; i++) cout << arr[i] << " ";
}