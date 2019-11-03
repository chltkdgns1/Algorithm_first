#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t,c = 1; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll a = (n - 1)*(n - 1), b = n * n;
		cout <<"#"<<c++<<" "<< a * 2 + 1 << " " << b * 2 - 1 << "\n";
	}
}