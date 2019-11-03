#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
bool check[10][10];
vector <ll> v[10];

ll solve(ll a, ll b) {
	ll s = 0, c = b % 10;
	
	for (auto a : v[c]) s +=a;

	ll res = ((a / b) / v[c].size()) * s;
	ll q = (a / b) % v[c].size();

	for (ll i = 0; i < q; i++) {
		res += v[c][i];
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll a, b; cin >> a >> b;
		ll c = b % 10;
		if (v[c].size()) cout << solve(a, b) << "\n";
		else {
			for (int i = 1;; i++) {
				ll d = (b % 10 * i) % 10;
				if (check[c][d]) break;
				check[c][d] = 1;
				v[c].push_back(d);
			}
			cout << solve(a, b) << "\n";
		}
	}
}