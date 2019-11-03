#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 1000000009
typedef long long ll;

ll dp[4][1001][4];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
bool check(int x, int y) {
	if (x >= 1 && y >= 1 && x <= n && y <= 3) return true;
	return false;
}

ll solve(int a, int b,int k) {
	bool ch = k == -1 ? 1 : 0;
	if (ch) k = 0;
	if (a == 1 && b == 1) return 1;
	ll &ref = dp[b][a][k];
	if (ref != -1) return ref;
	ref = 0;

	for (int i = 0; i < 4; i++) {
		int x = a + dx[i];
		int y = b + dy[i];
		if (!ch) {
			if (k % 2 == i % 2 && k != i) continue;
		}
		if (check(x, y)) {
			ref = (ref + solve(x, y,i)) % MAX;
		}
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solve(n, 3,-1) % MAX << "\n";
	system("pause");
}