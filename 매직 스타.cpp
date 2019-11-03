#include <iostream>
#include <vector>
using namespace std;
char map[6][10];
int alpa[13];
vector <pair<int, int>> v;
bool calStar() {
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	for (int i = 0; i < 4; i++) a += map[0 + i][4 - i] - 48;
	for (int i = 0; i < 4; i++) b += map[0 + i][4 + i] - 48;
	for (int i = 0; i < 4; i++) c += map[4 - i][4 - i] - 48;
	for (int i = 0; i < 4; i++) d += map[4 - i][4 + i] - 48;
	for (int i = 0; i < 4; i++) e += map[1][1 + 2*i] - 48;
	for (int i = 0; i < 4; i++) f += map[3][1 + 2*i] - 48;
	if (a == b && b == c && c == d && d == e && e == f) return true;
	return false;
}
void dfs(int index) {
	if (index == v.size()) {
		if (calStar()) {
			for (int i = 0; i < 5; i++) cout << map[i] << "\n";
			exit(0);
		}
		return;
	}
	int x = v[index].first, y = v[index].second;
	for (int i = 1; i <= 12; i++) {
		if (!alpa[i]) {
			alpa[i] = 1;
			map[y][x] = i + 64;
			dfs(index + 1);
			alpa[i] = 0;
			map[y][x] = 'x';
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		cin >> map[i];
		for (int j = 0; j < 9; j++) {
			if (map[i][j] >= 65 && map[i][j] <= 76) alpa[map[i][j] - 64] = 1;
			if (map[i][j] == 'x') v.push_back({ j,i });
		}
	}
	dfs(0);
}