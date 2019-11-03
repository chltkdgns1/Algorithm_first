#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <ll> v;
map <ll, ll> maps,tmaps;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m, a; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
		maps[a]++;
		tmaps[a]++;
	}

	sort(v.begin(), v.end());

	ll s = 0, e = v.size() - 1;
	ll resa = v[s], resb = v[e];

	if (resa == resb) {
		cout << 0 << "\n";
		return 0;
	}

	while (1) {
		ll a = v[s], b = v[e];

		ll acnt = maps[a], bcnt = maps[b];
		ll tacnt = tmaps[a], tbcnt = tmaps[b];
		if (acnt <= bcnt) {
			if (m < acnt) break;

			ll t = v[s + tacnt], r = t - a;

			if (m >= r * acnt) {
				m -= r * acnt;
				s += tacnt;
				resa = t;
				if (resa == resb) break;
				maps[t] += acnt;
			}
			else {
				resa += m / acnt;
				if (resa >= resb) resa = resb;
				break;
			}
		}
		else {
			if (m < bcnt) break;

			ll t = v[e - tbcnt], r = b - t;

			if (m >= r * bcnt) {
				m -= r * bcnt;
				e -= tbcnt;
				maps[t] += bcnt;
				if (resa == resb) break;
				resb = t;
			}
			else {
				resb -= m / bcnt;
				if (resb <= resa) resb = resa;
				break;
			}
		}
	}
	cout << resb - resa << "\n";
}