#include <iostream>
using namespace std;
#define MOD 1000000000
long long dp[101][10];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 1; i < n; i++) {
		for (int k = 0; k < 10; k++) {
			if (!k) dp[i + 1][k + 1] = (dp[i + 1][k + 1] + dp[i][k]) % MOD;
			else if (k == 9) dp[i + 1][k - 1] = (dp[i + 1][k - 1] + dp[i][k]) % MOD;
			else {
				dp[i + 1][k + 1] = (dp[i + 1][k + 1] + dp[i][k])%MOD;
				dp[i + 1][k - 1] = (dp[i][k] + dp[i + 1][k - 1])%MOD;
			}
		}
	}
	long long t = 0;
	for (int i = 0; i < 10; i++) t = (t + dp[n][i]) % MOD;
	cout << t << "\n";
}