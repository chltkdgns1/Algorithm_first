#include <iostream>
using namespace std;
int dp[3003];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	dp[9] = 1;
	int cnt = 2;
	for (int i = 9; i <= 2997; i += 3) {
		dp[i + 3] = dp[i] + cnt; cnt++;
	}
	cout << dp[n] << "\n";
}