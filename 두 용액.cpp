#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
typedef long long ll;
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	vector <ll> v, e;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		if (a < 0) v.push_back(a);
		else e.push_back(a);
	}
	sort(v.begin(), v.end()), sort(e.begin(), e.end());
	if (v.empty()) {
		cout << e[0] << " " << e[1];
		return 0;
	}
	else if (e.empty()) {
		cout << v[v.size() - 2] << " " << v[v.size() - 1];
		return 0;
	}
	ll a, b, c = 100000000000;
	if (v.size() >= 2) {
		a = v[v.size() - 2], b = v[v.size() - 1];
		c = abs(v[v.size() - 2] + v[v.size() - 1]);
	}
	if (e.size() >= 2) {
		if (c > abs(e[0] + e[1])) {
			a = e[0], b = e[1];
			c = e[0] + e[1];
		}
	}
	for (int i = 0; i < v.size(); i++) {
		ll d = lower_bound(e.begin(), e.end(), -v[i]) - e.begin();
		if (d == 0) {
			ll x = abs(v[i] + e[d]);
			if (x < c) {
				c = x;
				a = v[i], b = e[d];
			}
		}
		else if (d >= e.size()) {
			ll y = abs(v[i] + e[d - 1]);
			if (y < c) {
				c = y;
				a = v[i], b = e[d - 1];
			}
		}
		else {
			ll x = abs(v[i] + e[d]);
			ll y = abs(v[i] + e[d - 1]);
			if (x < y && x < c) {
				c = x;
				a = v[i], b = e[d];
			}
			else if (x >= y && y < c) {
				c = y;
				a = v[i], b = e[d - 1];
			}
		}
	}
	cout << a << " " << b << "\n";
}