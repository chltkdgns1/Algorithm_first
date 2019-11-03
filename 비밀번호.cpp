#include <iostream>
#include <algorithm>
#define inf 1000000000000000000
using namespace std;
typedef long long ll;
int getBinary(ll s) {
	int res = 0;
	while (s) {
		if (s % 2) res++;
		s /= 2;
	}
	return res;
}
ll sum2(ll a, ll b) {
	ll s = 0, c;
	while (b <= a) {
		if (a & b) s += b;
		b *= 2;
	}
	int x = getBinary(a);
	int y = getBinary(s);
	c = 1;
	while (x - y != 0) {
		s += c;
		y++;
		c *= 2;
	}
	return s;
}
ll sum1(ll a, ll b) {
	ll s = 0, c = b;
	while (b <= a) {
		if (a & b) s += b;
		b *= 2;
	}
	int x = getBinary(a);
	int y = getBinary(s);
	while (x - y != 0) {
		c /= 2;
		s += c;
		y++;
	}
	return s;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	int s = getBinary(n);
	ll a = 0, b = 0;
	for (ll i = 1; i <= inf; i *= 2) {
		if (getBinary(n + i) == s) {
			a = sum2(n + i, i * 2);
			break;
		}
	}
	for (ll i = 1; i <= n; i *= 2) {
		if (getBinary(n - i) == s) {
			b = sum1(n - i, i);
			break;
		}
	}
	cout << b << " " << a << "\n";
}