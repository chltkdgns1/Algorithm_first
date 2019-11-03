#include <iostream>
using namespace std;
#define mod 10007
int dp[50001][2];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	dp[1][0] = 1, dp[2][0] = 4,dp[2][1] = 3;

	for (int i = 3; i <= 50000; i++) {
		dp[i][0] = (3 * dp[i - 1][0] + dp[i - 1][1]) % mod;
		dp[i][1] = (2 * dp[i - 1][0] + dp[i - 1][1]) % mod;
	}
	while (t--) {
		int n; cin >> n;
		cout << dp[n][0] << " " << ((dp[n][0] + dp[n][1] - 1) * n) % mod << "\n";
	}
}

/*
	dp[1] = 1, dp[2] = 4;
	for (int i = 3; i <= 50000; i++) {
		dp[i] = (dp[i - 1] * 4 - dp[i - 2]) % mod;
	}

*/