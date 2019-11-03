#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

ll uclid(ll a, ll b) {
	if (a % b == 0) return b;
	uclid(b, a%b);
}
int main() {
	ll a, b, c, d, e, f;
	cin >> a >> b;
	bool br = 0;
	for (ll i = sqrt(a*b); i>=1; i--) {
		if ((a*b) % i == 0) {
			c = i, d = (a*b) / i;
			if (uclid(max(c, d),min(c,d)) == a) {
				e = c, f = d;
				br = 1;
				break;
			}
		}
	}
	if (br) {
		cout << min(e, f) << " " << max(e, f) << "\n";
	}
}