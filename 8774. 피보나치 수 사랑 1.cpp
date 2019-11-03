#include <iostream>
#include <map>
using namespace std;

map <int, int> dp;
int solve(int s) {
	if (s == 1 || s == 2) return 1;
	int &ref = dp[s];
	if (ref) return ref;

	return ref = (solve(s - 1) + solve(s - 2))% 1000000007;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	dp[1] = dp[2] = 1;
	solve(1000000);
	system("pause");
	for (int i = 0; i <= 100; i++) {
		cout << dp[i] << "\n";
	}
	system("pause");
}