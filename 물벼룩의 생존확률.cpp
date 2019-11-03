#include <iostream>
using namespace std;
int k, n;
long long dp[127][64];
long long dfs(int k,int time) {
	if (dp[k][time] != 0) return dp[k][time];
	if (k == 0) { return 0; }
	if (time == n) {
		return 1;
	}
	return dp[k][time] = dfs(k - 1, time + 1) + dfs(k + 1, time + 1);
}
int main() {
	cin >> k >> n;
	cout << dfs(k, 0) << endl;
}
