#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, c; cin >> a >> b >> c;
	if (c - b <= 0) cout << "-1" << endl;
	else {
		ll s = 0, e = 4000000000, m;
		while (s <= e) {
			m = (s + e) / 2;
			if (a + m * b < c * m) e = m - 1;
			else s = m + 1;
		}
		cout << s  << "\n";
	}
}