#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 987654321
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n, h; cin >> n >> h;
		ll Min = INF;
		for (int i = 0; i < n; i++) {
			ll a, b; cin >> a >> b;
			if (a - b <= 0) {
				if (a >= h) Min = 1;
				continue;
			}
			ll t = ((h - a) % (a - b) > 0) ? (h - a) / (a - b) + 2 :
				(h - a) / (a - b) + 1;
			Min = min(Min, t);
		}
		if (Min == INF) cout << -1 << "\n";
		else cout << Min << "\n";
	}
}