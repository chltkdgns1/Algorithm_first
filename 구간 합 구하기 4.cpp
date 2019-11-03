#include <iostream>
using namespace std;

int dp[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		int c; cin >> c;
		dp[i] = dp[i - 1] + c;
	}
	for (int i = 0; i < b; i++) {
		int x, y; cin >> x >> y;
		cout << dp[y] - dp[x - 1] << "\n";
	}
}