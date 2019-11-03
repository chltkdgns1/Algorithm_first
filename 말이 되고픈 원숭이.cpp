#include <iostream>
#include <queue>
using namespace std;
int n, a, b;
int map[201][201];
bool visit[201][201][32];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int dxe[8] = { 1,2,2,1,-1,-2,-2,-1 }, dye[8] = { 2,1,-1,-2,-2,-1,1,2 };
class Data {
public:
	int x, y, cnt, dis;
	Data(int x, int y, int cnt,int dis) :x(x), y(y), cnt(cnt),dis(dis) {}
};
bool check(int x, int y) {
	if (x >= 0 && x < a && y >= 0 && y < b) return true;
	return false;
}
void bfs() {
	queue <Data> q;
	q.push(Data(0, 0, 0, 0));
	visit[0][0][0] = 1;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int x = q.front().x, y = q.front().y;
			int c = q.front().cnt, d = q.front().dis;
			if (x == a - 1 && y == b - 1) {
				cout << d << "\n";
				return;
			}
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (check(nx, ny) && !visit[ny][nx][c] && !map[ny][nx]) {
					visit[ny][nx][c] = 1;
					q.push(Data(nx, ny, c, d + 1));
				}
			}
			if (c < n) {
				for (int k = 0; k < 8; k++) {
					int nx = x + dxe[k];
					int ny = y + dye[k];
					if (check(nx, ny) && !visit[ny][nx][c + 1] && !map[ny][nx]) {
						visit[ny][nx][c + 1] = 1;
						q.push(Data(nx, ny, c + 1, d + 1));
					}
				}
			}
		}
	}
	cout << -1 << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b;
	for (int i = 0; i < b; i++) {
		for (int k = 0; k < a; k++) {
			cin >> map[i][k];
		}
	}
	bfs();
}