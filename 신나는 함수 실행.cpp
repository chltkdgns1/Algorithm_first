#include <iostream>
#include <string.h>
using namespace std;

int dp[21][21][21];
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return dp[20][20][20] = w(20, 20, 20);
	int &res = dp[a][b][c];
	if (res != -1) return res;
	if (a < b && b < c) {
		return res = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	return res = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof(dp));
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
}