#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int main() {
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 1; i <= a.length(); i++) {
		for (int k = 1; k <= b.length(); k++) {
			if (a[i - 1] == b[k - 1]) {
				dp[i][k] = dp[i - 1][k - 1] + 1;
			}
			else {
				dp[i][k] = max(dp[i][k - 1], dp[i - 1][k]);
			}
		}
	}
	cout << ans << "\n";
}
 