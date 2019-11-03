#include <iostream>
#include <string.h>
using namespace std;
int dp[31];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	for (int k = 1; k <= b; k++) {
		dp[a] = b;
		dp[a - 1] = dp[a] - k;
		for (int i = a - 2; i >= 1; i--) {
			dp[i] = dp[i + 2] - dp[i + 1];
			if (dp[i] <= 0) break;
		}
		if (dp[1] >= 1 && dp[1] <= dp[2]) break;
		memset(dp, 0, sizeof(dp));
	}
	cout << dp[1] << "\n" << dp[2];
}