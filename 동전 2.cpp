#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;
long long dp[10001];
int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) dp[i] = INF;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a > m) continue;
		dp[a] = 1;
		int j = a;
		for (int k = 1; k <= m; k++) {
			if (k + a > m) break;
			if(dp[k + a] > dp[k] + 1) dp[k + a] = dp[k] + 1;
		}
	}
	if(dp[m] == INF) cout << -1 << "\n";
	else cout << dp[m] << "\n";
}