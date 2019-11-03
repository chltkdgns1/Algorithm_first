#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501];
int dp[501][501];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++) cin >> arr[i][k];
	}
	dp[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++) {
			int &a = dp[i +1][k], &b = dp[i + 1][k + 1];
			a = max(a, dp[i][k] + arr[i + 1][k]);
			b = max(b, dp[i][k] + arr[i + 1][k + 1]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, dp[n][i]);
	}
	cout << res << "\n";
}