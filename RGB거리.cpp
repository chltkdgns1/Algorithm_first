#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3], dp[1001][3], n;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 3; k++) {
			cin >> arr[i][k];
		}
	}
	for (int i = 0; i < 3; i++) dp[0][i] = arr[0][i];
	for (int i = 1; i < n; i++) {
		for (int k = 0; k < 3; k++) {
			dp[i][k] += arr[i][k];
			if (!k) dp[i][k] += min(dp[i - 1][k + 1], dp[i - 1][k + 2]);
			else if (k == 1) dp[i][k] += min(dp[i - 1][k - 1], dp[i - 1][k + 1]);
			else dp[i][k] += min(dp[i - 1][k - 2], dp[i - 1][k - 1]);
		}
	}
	cout << min(dp[n - 1][2], min(dp[n - 1][0], dp[n - 1][1])) << "\n";
}