#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b, c, t = 0, time = 0;
		cin >> a >> b >> c;
		t = c;
		while (1) {
			time++;
			a += t;
			if (a >= b) break;
			t += c;
		}
		cout << time << "\n";
	}
}