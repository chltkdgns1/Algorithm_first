#include <iostream>
using namespace std;
int map[1000][1000];
int dp[1001][1001];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	dp[1][1] = k - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] % 2) {
				if (map[i][j] == 1) {
					map[i][j] = 0;
					dp[i][j + 1]++;
				}
				else {
					map[i][j] = 1;
					dp[i + 1][j] ++;
				}
			}
			dp[i][j + 1] += dp[i][j] / 2;
			dp[i + 1][j] += dp[i][j] / 2;
 		}
	}
	int i = 1, j = 1;
	while (1) {
		if (map[i][j]) j++;
		else i++;
		if (i == n + 1 || j == m + 1) break;
	}
	cout << i << " " << j << "\n";
}