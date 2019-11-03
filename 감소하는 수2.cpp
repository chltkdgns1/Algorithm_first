#include <iostream>
#include <string.h>
using namespace std;long long dp[1000001];int main() {ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);memset(dp, -1, sizeof(dp));int n; cin >> n;dp[0] = 0;for (int i = 1; i <= 9; i++) dp[i] = i;int cnt = 10;for (int i = 1; i <= n; i++) {if (dp[i]) {int d = dp[i] % 10;for (int k = 0; k < d; k++) {dp[cnt++] = dp[i] * 10 + k;}}}cout << dp[n] << "\n";}

