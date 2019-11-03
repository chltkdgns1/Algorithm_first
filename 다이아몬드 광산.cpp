#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
bool map[751][751];
int dp[751][751][4];
int dx[4] = { -1,1,1,-1 };
int dy[4] = { 1,1,-1,-1 };
int a, b;
bool check(int x, int y) {
	if (0 <= x && x < b && 0 <= y && y < a) return 1;
	return 0;
}
int solve(int x, int y, int dir) {
	if (!check(x, y) || !map[y][x]) return 0;
	int &ref = dp[y][x][dir];
	if (ref != -1) return ref;
	ref = 1;
	ref += solve(x + dx[dir], y + dy[dir], dir);
	return ref;
}
bool cycle(int x, int y, int dir, int t, int cnt) {
	if (cnt == 4) return 1;
	int nx = x + dx[dir] * (t - 1);
	int ny = y + dy[dir] * (t - 1);
	if (!check(nx, ny)) return 0;
	int ref = dp[ny][nx][(dir + 1) % 4];
	if (ref >= t) return cycle(nx, ny, (dir + 1) % 4, t, cnt + 1);
	else return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		string c; cin >> c;
		for (int k = 0; k < c.length(); k++) {
			map[i][k] = c[k] - 48;
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			for (int z = 0; z < 4; z++) {
				if (dp[i][k][z] == -1) solve(k, i, z);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			for (int z = 0; z < 4; z++) {
				for (int w = dp[i][k][z]; w >= 1; w--) {
					if (res >= w) break;
					if (cycle(k, i, z, w , 1)) {
						res = max(res, w);
						break;
					}
				}
			}
		}
	}
	cout << res << "\n";
}