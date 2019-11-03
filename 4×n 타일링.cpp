#include <iostream>
#include <string.h>
#define inf 1000000007
using namespace std;

typedef long long ll;
ll dp[10001][(1 << 4)];

ll solve(int s, int t) {
	if (s < 0) return 0;
	if (!s && !t) return 1;

	ll &ref = dp[s][t];
	if (ref) return ref;

	ref = 0;
	if (!t) {
		ref = (ref + solve(s - 3, 0)) % inf;
		ref = (ref + solve(s - 1, 8)) % inf;
		ref = (ref + solve(s - 1, 1)) % inf;
	}
	else if (t == 8) {
		ref = (ref + solve(s - 2, 7)) % inf;
		ref = (ref + solve(s - 1, 10)) % inf;
	}
	else if (t == 1) {
		ref = (ref + solve(s - 2, 14)) % inf;
		ref = (ref + solve(s - 1, 11)) % inf;
	}
	else if (t == 10) {
		ref = (ref + solve(s - 1, 0)) % inf;
		ref = (ref + solve(s - 1, 15)) % inf;
	}
	else if (t == 11) {
		ref = (ref + solve(s - 1, 0)) % inf;
		ref = (ref + solve(s - 1, 16)) % inf;
	}
	else if (t == 7) ref = (ref + solve(s - 1, 8)) % inf;
	else if (t == 14) ref = (ref + solve(s - 1, 1)) % inf;
	else if (t == 15) ref = (ref + solve(s - 2, 10)) % inf;
	else if (t == 16) ref = (ref + solve(s - 2, 11)) % inf;

	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	
	solve(9999, 0);
	while (t--) {
		int n; cin >> n;
		if ((n % 3)) cout << 0 << "\n";
		else cout << dp[n][0] << "\n";
	}
}