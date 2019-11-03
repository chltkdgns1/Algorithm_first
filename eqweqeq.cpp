#include <iostream>
typedef long long ll;
using namespace std;
ll dp[10001];
ll go(int n) {
	if (dp[n]) return dp[n];
	for (int i = 0; i < n; i += 2) {
		dp[n] = (dp[n] + ((go(i) )*(go(n - i - 2) ))) % 987654321;
	}
	return dp[n];
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	dp[0] = 1;
	dp[2] = 1, dp[4] = 2, dp[6] = 5;
	cout << go(n) << "\n";
}