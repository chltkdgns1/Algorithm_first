#include <iostream>
using namespace std;
typedef long long ll;
ll dp[40][40];
ll nCr(int n, int r) {
	if (dp[n][r]) return dp[n][r];
	if (n == r || r == 0) return 1;
	if (r == 1) return n;
	return dp[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	cout<<nCr(m - 1, m - n)<<"\n";
}