#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a; cin >> a;
		if (a == 2) cout << 2 << "\n";
		else {
			if (!(a % 2)) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
	}
}