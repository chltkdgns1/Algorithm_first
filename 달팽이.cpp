#include <iostream>
using namespace std;

int map[1000][1000];
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int x = n / 2, y = n / 2, cnt = 1, go= 1;
	int dir = 0; 
	bool check = 0;
	map[y][x] = cnt;
	int res_a, res_b;
	while (1) {
		for (int i = 0; i < 2 * go; i++) {
			if (i == go) {
				dir++;
				if (dir == 4) dir = 0;
			}
			x += dx[dir], y += dy[dir];
			cnt++;
			map[y][x] = cnt;
			if (cnt == m) res_a = y + 1, res_b = x + 1;
			if (cnt == n * n) { check = 1; break; }
		}
		dir++;
		if (dir == 4) dir = 0;
		if (check) break;
		go++;
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << map[i][k] << " ";
		}
		cout << "\n";
	}
	cout << res_a << " " << res_b << "\n";
}

// 1 1 2 2 3 3 4 4 5 5 6 6
// 2 4 6 8 10 12 