#include <iostream>
using namespace std;

int arr[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		for (int i = a; i <= n; i += a) {
			arr[i] = 1;
		}
	}
	int t = 0;
	for (int i = 0; i <= n; i++) {
		if (arr[i]) t += i;
	}
	cout << t << "\n";
}