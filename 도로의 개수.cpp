#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[110][110];
int n, m, k;

bool check(int x, int y) {
	if (x >= 0 && x <= n && y >= 0 && y <= m) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;  
		if (a == c) {
			if(!dp[max(b, d)][a] || dp[max(b, d)][a] == -2) dp[max(b, d)][a] += -1;
		}
		else if (b == d) {
			if (!dp[b][max(a, c)] || dp[b][max(a, c)] == -1) dp[b][max(a, c)] += -2;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i <= m; i++) {
		for (int s = 0; s <= n; s++) {
			if (dp[i][s] == -1) {
				dp[i][s] = 0;
				if (check(s - 1, i)) dp[i][s] += dp[i][s - 1];
			}
			else if (dp[i][s] == -2) {
				dp[i][s] = 0;
				if (check(s, i - 1)) dp[i][s] += dp[i - 1][s];
			}
			else if (dp[i][s] == -3) dp[i][s] = 0;
			else {
				if (check(s, i - 1)) dp[i][s] += dp[i - 1][s];
				if (check(s - 1, i)) dp[i][s] += dp[i][s - 1];
			}
		}
	}
	cout << dp[m][n] << "\n";
}