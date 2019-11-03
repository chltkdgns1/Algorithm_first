#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, s = 0; cin >> n;
		for (int i = 1; i <= n; i++) {
			if (i % 2) s += i;
		}
		cout << s << "\n";
	}
}