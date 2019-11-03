#include <iostream>
using namespace std;
int main() {
	while (1) {
		int t; cin >> t;
		if (!t) break;
		int l = 1, r = 50;
		while (l <= r) {
			int m = (l + r) / 2;
			cout << m << " ";
			if (m > t) r = m - 1;
			else if (m < t) l = m + 1;
			else break;
		}
		cout << "\n";
	}
}