#include <iostream>
using namespace std;
int arr[100];
long long dp[101][21];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0][arr[0]]++;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - arr[i] >=0) dp[i][j - arr[i]] += dp[i - 1][j];
			if(j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
		}
	}
	cout << dp[n - 2][arr[n - 1]] << endl;
	return 0;
}