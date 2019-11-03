#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll a, b; cin >> a >> b;
		ll e = a - b;
		if (e == 1) {
			cout << "NO" << "\n";
			continue;
		}
		if (e == 2 || e == 3) {
			cout << "YES" << "\n";
			continue;
		}
		for (ll i = 2; i*i <= e; i++) {
			if (!(e % i)) {
				bool ch = 0;
				for (int k = 2; k*k <= i; k++) {
					if (!(i % k)) {
						ch = 1;
						break;
					}
				}
				if (!ch) cout << "YES" << "\n";
				else cout << "NO" << "\n";
				break;
			}
		}
	}
}