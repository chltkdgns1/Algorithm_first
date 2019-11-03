#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
bool visit[201][201][2];
int dx[4] = { 1,0,-1,0 }; 
int dy[4] = { 0,1,0,-1 };
class Data {
public:
	int x, y, c, d;
};
bool check(int x, int y) {
	if (x >= 0 && x <= 200 && y >= 0 && y <= 200) return true;
	return false;
}
void bfs(int x, int y, int c1, int d1) {
	for (int i = 0; i < 2; i++) visit[y][x][i] = 1;
	queue <Data> q;
	q.push({ x,y,0,-1 });
	while (!q.empty()) {
		int nx = q.front().x, ny = q.front().y;
		int cnt = q.front().c,dir = q.front().d;
		if (nx == c1 && ny == d1) {
			cout << cnt << "\n";
			return;
		}
		q.pop();
		int ax, ay;
		if (dir == -1) {
			for (int k = 0; k < 4; k++) {
				ax = nx + dx[k];
				ay = ny + dy[k];
				if (check(ax, ay)) {
					int w = k % 2 == 0 ? 0 : 1;
					if (!visit[ay][ax][w]) {
						q.push({ ax,ay,cnt + 1,w });
						visit[ay][ax][w] = 1;
					}
				}
			}
		}
		else if (!dir) {
			for (int k = 1; k <= 3; k += 2) {
				ax = nx + dx[k];
				ay = ny + dy[k];
				if (check(ax, ay)) {
					int w = k % 2 == 0 ? 0 : 1;
					if (!visit[ay][ax][w]) {
						q.push({ ax,ay,cnt + 1,w });
						visit[ay][ax][w] = 1;
					}
				}
			}
		}
		else {
			for (int k = 0; k <= 2; k += 2) {
				ax = nx + dx[k];
				ay = ny + dy[k];
				if (check(ax, ay)) {
					int w = k % 2 == 0 ? 0 : 1;
					if (!visit[ay][ax][w]) {
						q.push({ ax,ay,cnt + 1,w });
						visit[ay][ax][w] = 1;
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,ct=1; cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a += 100, b += 100,c += 100, d += 100;
		cout << "#" << ct++ << " "; bfs(a, b, c, d);
		memset(visit, 0, sizeof(visit));
	}
}