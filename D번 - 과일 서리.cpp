#include <iostream>
typedef long long ll;
using namespace std;

ll dp[40][40];
ll ncr(int n, int r) {
	ll &res = dp[n][r];
	if (res) return dp[n][r];
	if (r == 1) return n;
	if (r == 0 ) return 1;
	if(n == r) return 1;
	return res = ncr(n - 1, r) + ncr(n - 1, r - 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	cout << ncr(m - n, n) + 1 << "\n";

}