#include <iostream>
using namespace std;
int dp[100000],arr[4] = { 7,5,1,2 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	dp[1] = dp[2] = dp[7] = dp[5] = 1;
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i <= 100000; i++) {
			if (dp[i]) {
				if (!dp[i + arr[k]]) dp[i + arr[k]] = dp[i] + 1;
				else {
					if (dp[i + arr[k]] > dp[i] + 1) dp[i + arr[k]] = dp[i] + 1;
				}
			}
		}
	}
	cout << dp[n] << "\n";
}