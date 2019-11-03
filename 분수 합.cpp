#include <iostream>
typedef long long ll;
using namespace std;
ll n(ll a, ll b) {
	if (a % b == 0) return b;
	n(b, a%b);
}
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ll x = a * d + c * b, y = b * d,f;
	f = n(x, y);
	cout << x / f << " " << y / f << "\n";
}