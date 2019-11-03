#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
bool visit[101][101][2];
int n, m, a, dx[4] = { 0,0,1, - 1 },dy[4] = { 1,-1,0,0 };

class Data {
public:
	int x, y, c,d;
};
void bfs(int x, int y) {
	visit[y][x][0] = 1;
	queue <Data> q;
	q.push({ x,y,0 });

	while (!q.empty()) {
		Data d = q.front();
		int x = d.x, y = d.y, c = d.c, dis = d.d;
		if (x == m - 1 && y == n - 1) {
			if(dis <= a) cout << dis << "\n";
			else cout << "Fail" << "\n";
			return;
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (c) {
					if (!visit[ny][nx][c]) {
						visit[ny][nx][c] = 1;
						q.push({ nx,ny,c,dis + 1});
					}
				}
				else {
					if (map[ny][nx] == 2 && !visit[ny][nx][1]) {
						visit[ny][nx][1] = 1;
						q.push({ nx,ny,1,dis + 1 });
					}
					else if (!map[ny][nx] && !visit[ny][nx][c]) {
						visit[ny][nx][c] = 1;
						q.push({ nx,ny,c,dis + 1 });
					}
				}
			}
		}
	}
	cout << "Fail" << "\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> a;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
		}
	}

	bfs(0, 0);
}