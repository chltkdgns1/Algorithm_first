#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[101][101][101];
int main() {
	string a, b, c;
	cin >> a >> b >> c;
	for (int i = 1; i <= a.length(); i++) {
		for (int k = 1; k <= b.length(); k++) {
			for (int q = 1; q <= c.length(); q++) {
				if (a[i - 1] == b[k - 1] && b[k - 1] == c[q - 1]) {
					dp[i][k][q] = dp[i - 1][k - 1][q - 1] + 1;
				}
				else dp[i][k][q] = max(dp[i-1][k][q],max(dp[i][k - 1][q], dp[i][k][q - 1]));	
			}
		}
	}
	cout << dp[a.length()][b.length()][c.length()] << "\n";
}