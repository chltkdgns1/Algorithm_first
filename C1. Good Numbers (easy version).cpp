#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;

vector <ll> v;
ll dp[50];

ll solve(int idx,ll n) {
	if (idx == v.size()) return 0;

	ll &ref = dp[idx];
	if (ref) return ref;

	ll a = n, b = n;

	ll t = solve(idx + 1, n) + v[idx];
	ll q = solve(idx + 1, n);

	a = max(a, t);
	b = max(b, q);

	
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q; cin >> q;

	ll d = 1;
	for(int i=0;i<50;i++){
		v.push_back(d);
		if (d > 1e18) break;
		d *= 3;
	}

	while (q--) {
		ll n; cin >> n;
		memset(dp, 0, sizeof(dp));
		cout << solve(0, n) << "\n";
	}
	system("pause");
}