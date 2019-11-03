#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[101][101];
int sol(int a, int z) {
	int &r = dp[a][z];
	if (!a || !z) return r = 1;
	if (r != -1) return r;
	return r = min(sol(a - 1, z) + sol(a, z - 1),1000000000);
}
int main() {
	int n, m, k;
	string t;
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	int a = n, b = m;
	sol(n, m);
	if (k > dp[n][m]) { cout << -1 << "\n"; return 0; }
	for (int i = 0; i < n + m; i++) {
		if (!a || !b) break;
		if (dp[a - 1][b] >= k) {
			t += 'a';
			a--;
		}
		else {
			k -= dp[a - 1][b];
			t += 'z';
			b--;
		}
	}
	while (a--)t += 'a';
	while (b--)t += 'z';
	cout << t << "\n";
}