#include <iostream>
using namespace std;
long long dp[33334];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	dp[2] = 2;
	for (int i = 3; i <= 33333; i++) dp[i] = (dp[i - 1] * 3) % (1000000009);
	cout << dp[n] << "\n";
}