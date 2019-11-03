#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

class ball {
public:
	int r_x, r_y, b_x, b_y;
};
ball b;
queue <ball> q;
char map[11][11];
bool check[11][11][11][11];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;
int key;
void bfs() {
	int cnt = 1;
	while (1) {
		int len = q.size();
		if (cnt == 11) {
			key = 0; return;
		}
		for (int i = 0; i < len; i++) {
			int x1 = q.front().r_x, y1 = q.front().r_y, x2 = q.front().b_x, y2 = q.front().b_y;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x_1 = x1, y_1 = y1, x_2 = x2, y_2 = y2;
				int br = 0;
				while (1) {
					x_2 += dx[i];
					y_2 += dy[i];
					if (x_2 >= 0 && y_2 >= 0 && x_2 < m && y_2 < n) {
						if (map[y_2][x_2] == 'O') {
							br = 1;
							break;
						}
						else if (map[y_2][x_2] == '#') {
							x_2 -= dx[i];
							y_2 -= dy[i];
							break;
						}
					}
				}
				if (br == 1) { br = 0; continue; }
				while (1) {
					x_1 += dx[i];
					y_1 += dy[i];
					if (x_1 >= 0 && y_1 >= 0 && x_1 < m && y_1 < n) {
						if (map[y_1][x_1] == 'O') {
							key = cnt;
							return;
						}
						else if (map[y_1][x_1] == '#' ) {
							x_1 -= dx[i];
							y_1 -= dy[i];
							if (x_1 == x_2 && y_1 == y_2) {
								if (x1 != x2) {
									if (abs(x1 - x_1) < abs(x2 - x_2)) x_2 -= dx[i];	
									else x_1 -= dx[i];
								}
								else if (y1 != y2) {
									if (abs(y1 - y_1) < abs(y2 - y_2)) y_2 -= dy[i];
									else y_1 -= dy[i];
								}
							}
							if (check[y_1][x_1][y_2][x_2] == true) {
								break;
							}
							check[y_1][x_1][y_2][x_2] = true;
							b.r_x = x_1; b.r_y = y_1; b.b_x = x_2; b.b_y = y_2;
							q.push(b);
							break;
						}
					}
				}
			}
		}
		cnt++;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'B') {
				b.b_x = j;
				b.b_y = i;
			}
			else if (map[i][j] == 'R') {
				b.r_x = j;
				b.r_y = i;

			}
		}
	}
	q.push(b);
	bfs();
	if (key) cout << key << endl;
	else cout << -1 << endl;
}