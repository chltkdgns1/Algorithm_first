#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a = 0, b = 0;
	for (int i = 0; i < 5; i++) {
		int t = 0;
		for (int k = 0; k < 4; k++) {
			int c; cin >> c;
			t += c;
		}
		if (b < t) b = t, a = i + 1;
	}
	cout << a << " " << b << "\n";
}