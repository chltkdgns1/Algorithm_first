#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) dp[i] = 987654321;
	dp[n] = 0;
	for (int i = n ; i >= 1; i--) {
		if(!(i % 3)) dp[i / 3] = min(dp[i/3],dp[i] + 1);
		if (!(i % 2)) dp[i / 2] = min(dp[i/2],dp[i] + 1);
		dp[i - 1] = min(dp[i - 1], dp[i] + 1);
	}
	cout << dp[1] << "\n";
}