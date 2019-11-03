#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
class Data {
public:
	int x, y, h;
};
Data d;
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
int map[6][6][6];
int r_map[6][6][6];
bool check[6][6][6];
int min1 = 1e9;

void cicle(int index) {
	int temp_map[6][6];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			temp_map[j][i] = map[index][i][4 - j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			map[index][i][j] = temp_map[i][j];
		}
	}
}
void bfs(int xp, int yp,int hp) {
	queue <Data> q;
	d.x = xp, d.y = yp, d.h = hp;
	q.push(d);
	check[hp][yp][xp] = true;
	int cnt = 0;
	while (1) {
		int len = q.size();
		if (len == 0) return;
		for (int i = 0; i < len; i++) {
			int nx = q.front().x;
			int ny = q.front().y;
			int nh = q.front().h;
			if (nx == abs(xp -4) && ny == abs(yp - 4) && nh == abs(hp - 4)) {
				if (min1 > cnt) min1 = cnt;
				return;
			}
			q.pop();
			for (int i = 0; i < 6; i++) {
				int x = nx + dx[i];
				int y = ny + dy[i];
				int h = nh + dh[i];
				if (x >= 0 && x < 5 && y >= 0 && y < 5 && h >= 0 && h < 5) {
					if (check[h][y][x] == false && map[h][y][x] == 1) {
						check[h][y][x] = true;
						d.x = x, d.y = y, d.h = h;
						q.push(d);
					}
				}
 			}
		}
		cnt++;
	}
}

void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				check[i][j][k] = 0;
			}
		}
	}
}

void dfs(int index) {
	if (index == 5) {
		// 0 0 0 0 4 0 0 0 4 0 4 4
		// 4 0 0 4 4 0 4 0 4 4 4 4
		if (map[0][0][0] != 0 && map[4][4][4] != 0) {
			bfs(0, 0, 0);
			init();
		}
		if (map[4][0][0] != 0 && map[0][4][4] != 0) {
			bfs(4, 0, 0);
			init();
		}
		if (map[0][4][0] != 0 && map[4][0][4] != 0) {
			bfs(0, 4, 0);
			init();
		}
		if (map[0][0][4] != 0 && map[4][4][0] != 0) {
			bfs(0, 0, 4);
			init();
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		dfs(index + 1);
		cicle(index);
	}
}
int f[5];
void dfs2(int index) {
	if (index == 5) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					map[i][j][k] = r_map[f[i]][j][k];
				}
			}
		}
		dfs(0);
		return;
	}
	for (int i = 0; i < 5; i++) {
		bool br = 0;
		for (int j = 0; j < 5; j++) {
			if (f[j] == i) { br = 1; break; }
		}
		if (!br) {
			f[index] = i;
			dfs2(index + 1);
			f[index] = -1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> r_map[i][j][k];
			}
		}
	}
	for (int i = 0; i < 5; i++) f[i] = -1;
	dfs2(0);
	if (min1 == 1e9) cout << "-1" << "\n";
	else cout << min1 << "\n";
}