#include <iostream>
#include <string.h>
using namespace std;
int map[301][301];
int n, m, a;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
bool check(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}
void cicle() {
	int visit[301][301];
	int temp[301][301];
	memset(temp, 0, sizeof(temp));
	memset(visit, 0, sizeof(visit));
	int a = 0, cnt = 1;
	while (1) {
		int x = a, y = a;
		if (temp[y][x] != 0) break;
		int dir = 0;
		while (1) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (visit[ny][nx] == cnt) break;
			if (check(nx, ny) && temp[ny][nx] == 0) {
				temp[ny][nx] = map[y][x];
				visit[ny][nx] = cnt;
				x = nx, y = ny;
			}
			else {dir++;if (dir == 4) dir = 0;}
		}
		a++, cnt++;
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			map[i][k] = temp[i][k];
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> a;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) cin >> map[i][k];
	}
	for (int i = 0; i < a; i++) cicle();
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cout << map[i][k] << " ";
		}
		cout << "\n";
	}
}