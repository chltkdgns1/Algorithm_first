#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll a, b, c; cin >> a >> b >> c;
		ll l = 0, r = 100000000000, res = 0;
		if (!c && a > b) {
			cout << 1 << "\n";
			continue;
		}
		if (a > b + c) {
			cout << c + 1 << "\n";
			continue;
		}
		while (l <= r) {
			ll m = (l + r) / 2;
			if (m + b < c - m + a) l = m + 1;
			else r = m - 1, res = m;
		}
		cout << res << "\n";
	}
}