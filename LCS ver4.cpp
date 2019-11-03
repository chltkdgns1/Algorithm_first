#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1010][1010];
bool check[1010][1010];
string res,a, b, c;
void dfs(int i, int k) {
	if (i < 1 || k < 1) return;
	if (check[i][k]) return;
	check[i][k] = 1;
	if (dp[i][k] == dp[i - 1][k]) dfs(i - 1, k);
	else if (dp[i][k] == dp[i][k - 1]) dfs(i, k - 1);
	else {res += a[i - 1];dfs(i - 1, k - 1);}
}
int main() {
	cin >> a >> b;
	int ans = 0;
	int alen = a.length(), blen = b.length();
	for (int i = 1; i <= alen; i++) {
		for (int k = 1; k <= blen; k++) {
			if (a[i - 1] == b[k - 1]) dp[i][k] = dp[i - 1][k - 1] + 1;
			else dp[i][k] = max(dp[i][k - 1], dp[i - 1][k]);
		}
	}
	dfs(alen, blen);
	reverse(res.begin(), res.end());
	cout << dp[alen][blen] << "\n" << res << "\n";
}