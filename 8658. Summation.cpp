#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, cnt = 1; cin >> t;
	while (t--) {
		int mx = 0, mn = 987654321;
		for (int i = 0; i < 10; i++) {
			int a; cin >> a;
			int s = 0;
			while (a) {
				s += a % 10;
				a /= 10;
			}
			mx = max(mx, s);
			mn = min(mn, s);
		}
		cout << "#" << cnt++ << " " << mx << " " << mn << "\n";
	}
}