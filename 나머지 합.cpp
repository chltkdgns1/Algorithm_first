#include <iostream>
#include <unordered_map>
typedef long long ll;
using namespace std;
unordered_map <ll, ll> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	ll d = 0;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		d = a + d;
		v[d%m]++;
	}
	v[0]++;
	ll res = 0;
	for (auto a : v) res += ((a.second - 1)*a.second) / 2;
	cout << res << "\n";
}