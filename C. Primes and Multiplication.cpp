#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
typedef long long ll;

ll pow2(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		b >>= 1;
		a = (a *a) % mod;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b ,t ; cin >> a >> b;
	t = a;

	vector <int> v;
	for (int i = 2; i*i <= a; i++) {
		if (!(t % i)) {
			v.push_back(i);
			while (!(t %i)) t /= i;	
		}
	}
	if (t != 1) v.push_back(t);

	ll res = 1;
	for (auto a : v) {
		ll x = a, y ;
		while (x <= b) {
			y = b / x;
			res = (res * pow2(a , y)) % mod;
			if (b / x < a) break;
			x *= a;
		}
	}
	cout << res << "\n";
}