#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
vector <ll> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b; cin >> a >> b;
	ll e = 1;
	for (int i = 0; i < 64; i++) {
		v.push_back(e);
		e *= 2;
	}
	ll cnt = 0, res = 0;
	for (int k = v.size() - 1; k >= 0; k--) {
		ll c = (a - 1) / v[k], d = b / v[k];
		res += (d - c - cnt)*v[k];
		cnt += (d - c - cnt);
	}
	cout << res << "\n";
}