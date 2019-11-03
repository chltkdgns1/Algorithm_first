#include <iostream>
#define MOD 1000000000
typedef long long ll;
using namespace std;

ll dp[101][10][(1 << 10)];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++) dp[1][i][(1 << i)] = 1;
	for (int i = 1; i < n; i++) {
		for (int k = 0; k < 10; k++) {
			for (int z = 1; z < 1024; z++) {
				if (!k) dp[i + 1][k + 1][z | (1 << 1)] = (dp[i + 1][k + 1][z | (1 << 1)] + dp[i][k][z]) % MOD;// 무작정 더하면 안됨
				else if (k == 9) dp[i + 1][k - 1][z | (1 << 8)] = (dp[i + 1][k - 1][z | (1 << 8)] + dp[i][k][z]) % MOD;
				else {
					dp[i + 1][k + 1][z | (1 << (k + 1))] = (dp[i + 1][k + 1][z | (1 << (k + 1))] + dp[i][k][z]) % MOD;
					dp[i + 1][k - 1][z | (1 << (k - 1))] = (dp[i + 1][k - 1][z | (1 << (k - 1))] + dp[i][k][z]) % MOD;
				}
			}
		}
	}

	ll s = 0;
	for (int i = 0; i < 10; i++) {
		s = (s + dp[n][i][1023]) % 1000000000;
	}
	cout << s << "\n";
}
