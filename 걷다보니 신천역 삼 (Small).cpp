#include <iostream>
using namespace std;
long long dp[40][10];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	dp[1][1] = dp[2][1] = 1;
	for (int i = 1; i <= 9; i++) {
		for (int k = 0; k <= 40; k++) {
			if (dp[k][i - 1]) {
				dp[k + 1][i] += dp[k][i - 1];
				dp[k][i] += dp[k][i - 1];
				dp[k + 2][i] += dp[k][i - 1];
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= 40; i++) {
		if (dp[i][n] && !(i % 3)) res += dp[i][n];
	}
	cout << res << "\n";
	system("pause");
}