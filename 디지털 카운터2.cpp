#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
typedef long long ll;
using namespace std;
int arr[10] = { 6,2,5,5,4,5,6,3,7,5 };
ll pows(int a, int b) {
	ll res = 1;
	while (b--) res *= a;
	return res;
}
string tostring(ll s) {
	string res;
	while (s) {
		res += (s % 10) + 48;
		s /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}
ll sto(string s) {
	ll t = 1, res = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		res += (s[i] - 48)*t;
		t *= 10;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		string s; cin >> s;
		ll t = 0, n = s.length();
		for (int i = 0; i < n; i++) t += arr[s[i] - 48];
		ll r = sto(s);
		ll a = pows(10, n);
		for (ll i = 1; i <= a; i++) {
			ll d = ((r + i) % a), q = 0;
			string e = tostring(d);
			for (int i = 0; i < (n - e.length()); i++) q += arr[0];
			for (int i = 0; i < e.length(); i++) q += arr[e[i] - 48];
			if (q == t) {
				cout << i << "\n";
				break;
			}
		}
	}
	system("pause");
}