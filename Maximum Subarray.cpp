#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int dp[1001] = { 0 };
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			dp[i] = a + dp[i - 1];
		}
		int max = -987654321;
		for (int i = n; i >= 1; i--) {
			for (int k = 0; k < i; k++) {
				if (dp[i] - dp[k] > max) max = dp[i] - dp[k];
			}
		}
		cout << max << "\n";
	}
}