#include <iostream>
using namespace std;

int dp[301];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c, d; cin >> a >> b >> c >> d;
	dp[d] = 1;
	for (int i = d; i >= 0; i--) {
		if (dp[i]) {
			if (i - a >= 0) dp[i - a] = 1;
			if (i - b >= 0) dp[i - b] = 1;
			if (i - c >= 0) dp[i - c] = 1;
		}
	}
	if (dp[0]) cout << 1 << "\n";
	else cout << 0 << "\n";
}