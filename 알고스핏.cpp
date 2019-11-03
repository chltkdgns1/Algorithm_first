#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
int dist[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
void bfs(int xpos, int ypos) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos } );
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
				if (map[ny][nx] == '1') {
					if (dist[ny][nx] > dist[y][x] + 1) {
						dist[ny][nx] = dist[y][x] + 1;
						q.push({ nx,ny });
					}
				}
				else {
					if (dist[ny][nx] > dist[y][x]) {
						dist[ny][nx] = dist[y][x];
						q.push({ nx,ny });
					}
				}

			}
		}

	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = 10001;
		}
	}
	dist[0][0] = 0;
	bfs(0, 0);
	cout << dist[n - 1][m - 1] << "\n";
}