#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll n, p, q;
map <ll, ll> m;
ll solve(ll n) {
	if (m[n]) return m[n];
	if (!n) return 1;
	return m[n] = solve(n / p) + solve(n / q);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	 cin >> n >> p >> q;
	 cout << solve(n) << "\n";
}