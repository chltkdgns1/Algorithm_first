#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long t = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a; t += a;
		}
		cout << t << "\n";
	}
}