#include <iostream>
using namespace std;
typedef long long ll;

ll dp[20][20];

ll solve(int n, int r) {
	ll &ref = dp[n][r];
	if (ref) return ref;
	if (r == 1) return ref = n;
	if (r == 0 || n == r) return ref = 1;
	return ref = solve(n - 1, r) + solve(n - 1, r - 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll res = 0;
	for (int i = 0; i <= 15; i++) {
		res += solve(15, i);
	}
	cout << res << "\n";
	system("pause");
}