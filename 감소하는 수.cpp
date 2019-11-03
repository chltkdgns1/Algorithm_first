#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int dp[10][9];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	if (!n) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i <= 9; i++) dp[i][1] = 1;
	for (int i = 2; i <= 8; i++) {
		for (int k = 1; k <= 9; k++) {
			for (int z = 0; z < k; z++) {
				dp[k][i] += dp[z][i - 1];
			}
		}
	}
}