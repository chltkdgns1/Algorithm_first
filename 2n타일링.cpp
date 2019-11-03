#include <iostream>
using namespace std;
typedef long long ll;
ll dp[60001], n;
ll solve(int index) {
	if (index < 0) return 0;
	if (!index) return 1;

	ll &ref = dp[index];
	if (ref) return ref;

	ref = 0;
	ref = (solve(index - 1) + ref) % 1000000007;
	ref = (solve(index - 2) + ref) % 1000000007;
	return ref;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	cout << solve(n) << "\n";
}