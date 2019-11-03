#include <iostream>
using namespace std;
long long dp[10001];
int n, m;
long long solve(int s) {
	if (s == 0) return 1;
	if (s < 0) return 0;
	if (dp[s]) return dp[s];
	return dp[s] = (solve(s - 1) + solve(s - m))%1000000007;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cout << solve(n) << "\n";
	system("pause");
}