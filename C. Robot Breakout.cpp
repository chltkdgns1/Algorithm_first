#include <iostream>
#include <algorithm>
#define inf 100000
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;

		int x,y,a, b, c, d;
		int aa = -inf, bb = inf, cc = inf, dd = -inf;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> a >> b >> c >> d;
			if (!a) aa = max(aa, x);
			if (!b) bb = min(bb, y);
			if (!c) cc = min(cc, x);
			if (!d) dd = max(dd, y);
		}
		if (aa > cc || dd > bb) cout << 0 << "\n";
		else cout << 1 << " " << aa << " " << bb << "\n";
	}
}