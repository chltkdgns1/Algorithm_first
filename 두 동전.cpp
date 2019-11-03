#include <iostream>
#include <queue>
using namespace std;
char map[21][21];
class Data {
public:
	int x, y, d,a, b;
};
bool visit[21][21][21][21];
int n, m;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool check(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}
queue <Data> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int a = q.front().a, b = q.front().b;
		int d = q.front().d;
		q.pop();
		if (d >= 10) continue;
		for (int i = 0; i < 4; i++) {
			int ax = a + dx[i], by = b + dy[i];
			int nx = x + dx[i], ny = y + dy[i];
			if ((!check(ax, by) && check(nx, ny)) ||
				(check(ax, by) && !check(nx, ny))) {
				cout << d + 1 << "\n";
				return;
			}
			else if (check(ax, by) && check(nx, ny)) {
				if (map[by][ax] == '#' && map[ny][nx] != '#') {
					if (!visit[b][a][ny][nx] && !visit[ny][nx][b][a]) {
						visit[b][a][ny][nx] = visit[ny][nx][b][a] = 1;
						Data e;
						e.a = a, e.b = b;
						e.x = nx, e.y = ny;
						e.d = d + 1;
						q.push(e);
					}
				}
				else if (map[by][ax] != '#' && map[ny][nx] == '#') {
					if (!visit[by][ax][y][x] && !visit[y][x][by][ax]) {
						visit[by][ax][y][x] = visit[y][x][by][ax] = 1;
						Data e;
						e.a = ax, e.b = by;
						e.x = x, e.y = y;
						e.d = d + 1;
						q.push(e);
					}
				}
				else if(map[by][ax] != '#' && map[ny][nx] != '#'){
					if (!visit[by][ax][ny][nx] && !visit[ny][nx][by][ax]) {
						visit[by][ax][ny][nx] = visit[ny][nx][by][ax] = 1;
						Data e;
						e.a = ax, e.b = by;
						e.x = nx, e.y = ny;
						e.d = d + 1;
						q.push(e);
					}
				}
			}
		}
	}
	cout << -1 << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	pair <int, int> v[2];
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k] == 'o') v[c].first = k, v[c].second = i,c++;
		}
	}
	Data d;
	d.a = v[0].first, d.b = v[0].second, d.x = v[1].first, d.y = v[1].second;
	d.d = 0;
	q.push(d);
	visit[v[0].second][v[0].first][v[1].second][v[1].first] = 1;
	visit[v[1].second][v[1].first][v[0].second][v[0].first] = 1;
	bfs();
}