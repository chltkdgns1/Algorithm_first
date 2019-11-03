#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

char map[1510][1510];
int dis[1510][1510];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[1510][1510];
int n, m;
pair <int, int> xy[2];
queue <pair<pair<int, int>,int>> q;
int max1;
bool check(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}

void bfs() {
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int a = q.front().first.first;
			int b = q.front().first.second;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = a + dx[i];
				int ny = b + dy[i];
				if (check(nx, ny)) {
					if (!visit[ny][nx] && map[ny][nx] == 'X') {
						visit[ny][nx] = 1;
						dis[ny][nx] = c + 1;
						if (max1 < dis[ny][nx]) max1 = dis[ny][nx];
						q.push({ { nx,ny },c + 1 });
					}
				}
			}
		}
	}
}

bool go(int x, int y,int melt) {
	visit[y][x] = 1;
	queue <pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		if (nx == xy[1].first && ny == xy[1].second) {
			return true;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = nx + dx[i];
			int y = ny + dy[i];
			if (check(x, y)) {
				if (!visit[y][x] && melt >= dis[y][x]) {
					visit[y][x] = 1;
					q.push({ x,y });
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int x, y, cnt = 0, time = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k] == 'L') {
				xy[cnt].first = k, xy[cnt].second = i;
				cnt++;
				q.push({{ k,i }, 0});
			}
			else if (map[i][k] == '.') q.push({ { k,i }, 0 });
		}
	}
	bfs();
	memset(visit, 0, sizeof(visit));
	int left = 0, right = max1, mid;
	int res = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (go(xy[0].first, xy[0].second, mid)) { // 참일 경우
			res = mid;
			right = mid - 1;
		}
		else left = mid + 1;
		memset(visit, 0, sizeof(visit));
	}
	cout << res << "\n";
}