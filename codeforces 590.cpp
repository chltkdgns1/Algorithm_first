#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a; cin >> a;
		int sum = 0;
		for (int i = 0; i < a; i++) {
			int c; cin >> c;
			sum += c;
		}
		if (!(sum % a)) cout << sum / a << "\n";
		else cout << sum / a + 1 << "\n";
	}
}