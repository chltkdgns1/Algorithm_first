#include <iostream>
using namespace std;
int ket[101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		for (int k = a; k <= b; k++) {
			ket[k] = c;
		}
	}
	for (int i = 1; i <= n; i++) cout << ket[i] << " ";
}