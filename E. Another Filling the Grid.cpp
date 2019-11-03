#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long ll;

ll Pow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	ll t = 1;
	for (int i = a; i >= 2; i--) t = (t*i) % mod;
	cout<< (t * Pow(b, a*(a - 1))) % mod<<"\n";
	system("pause");
}