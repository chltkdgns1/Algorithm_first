#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	ll cnt = 2;
	for (int i = 2; i <= 64; i++) {
		cnt *= 2;
		ll sum = (cnt - 1)*i + i - 1;
		if (sum >= n) {
			cout << i - 1 << "\n";
			break;
		}
	}
}