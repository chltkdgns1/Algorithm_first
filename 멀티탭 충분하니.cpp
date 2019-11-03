#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int t = 0;
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		t += a / 2 + a % 2;
	}
	if (n <= t) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}