#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	if (m == 0) {
		if (n < 6) {
			for (int i = 2; i <= n; i++) {
				if (i % 2 == 0) cout << 1 << "\n";
				else cout << 0 << "\n";
			}
		}
		else cout << "Love is open door" << "\n";
	}
	else {
		if (n < 6) {
			for (int i = 2; i <= n; i++) {
				if (i % 2 == 1) cout << 1 << "\n";
				else cout << 0 << "\n";
			}
		}
		else cout << "Love is open door" << "\n";
	}
}