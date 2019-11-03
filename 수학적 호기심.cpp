#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b, cnt = 0;
		cin >> a >> b;
		for (int i = 1; i < a; i++) {
			for (int k = i + 1; k < a; k++) {
				if (!((i*i + k * k + b) % (i*k))) {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}