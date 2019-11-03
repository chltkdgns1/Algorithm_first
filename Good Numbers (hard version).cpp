#include <iostream>
using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q; cin >> q;
	while (q--) {
		ll n, t = 1, hr = 3;
		cin >> n;

		while (t < n) {
			t += hr;
			hr *= 3;
		}

		while (hr) {
			if (t - hr >= n) t -= hr;
			hr /= 3;
		}

		cout << t << "\n";
	}
}