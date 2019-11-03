#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	int dp[11], sum[11];
	while (t--) {
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		ll a, b; cin >> a >> b;
		ll c = a / b; 
		int d = b % 10;

		for (int i = 1; i <= 10; i++) dp[i] = (dp[i - 1] + d) % 10;
		for (int i = 1; i <= 10; i++) sum[i] = dp[i] + sum[i - 1];
		cout << (c/10)*sum[10] + sum[c % 10] << "\n";
	}
}