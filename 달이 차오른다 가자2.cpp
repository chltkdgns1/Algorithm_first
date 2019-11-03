#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

char map[51][51];
int sx, sy, ex, ey;
bool visit[51][51][(1 << 6)];

int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int n, m;

class Data {
public:
	int x, y, dis, key;
};

int bfs(int x, int y) {
	visit[y][x][0] = 1;
	queue <Data> q;
	q.push({ x,y,0,0 });

	while (!q.empty()) {
		Data d = q.front();
		q.pop();

		int x = d.x, y = d.y, dis = d.dis, key = d.key;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			char a = map[ny][nx];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (a != '#') {
					int t = (key | (1 << a - 'a'));
					int w = (key & (1 << a - 'A'));
					if (a == '.' && !visit[ny][nx][key]) {
						visit[ny][nx][key] = 1;
						q.push({ nx,ny,dis + 1,key });
					}
					if (a >= 'a' && a <= 'z' && !visit[ny][nx][t]) {
						visit[ny][nx][t] = 1;
						q.push({ nx,ny,dis + 1,t });
					}
					if (a >= 'A' && a <= 'Z' && !visit[ny][nx][key]) {
						if (w) {
							visit[ny][nx][key] = 1;
							q.push({ nx,ny,dis + 1,key });
						}
					}
					if (a == '1' && !visit[ny][nx][key]) {
						return dis + 1;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			char a = map[i][k];
			if (a == '0') sx = k, sy = i,map[i][k] = '.';
			if (a == '1') ex = k, ey = i;
		}
	}

	cout << bfs(sx, sy) << "\n";
}