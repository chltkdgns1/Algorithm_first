#include <iostream>
using namespace std;
#define MAX (1<<15)
int dp[MAX + 1][5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i*i <= MAX; i++) {
		dp[i*i][1]++;
		for (int k = 1; k < 4; k++) {
			for (int j = 1; j <= MAX; j++) {
				if (dp[j][k] && j + i*i<=MAX) {
					dp[j + i * i][k + 1] += dp[j][k];
				}
			}
		}
	}
	while (1) {
		int n;
		cin >> n;
		if (!n) break;
		cout << dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] << "\n";
	}
}