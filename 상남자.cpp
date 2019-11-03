#include <iostream>
#include <queue>
using namespace std;
int l, r;
char map[1001][1001];
bool visit[1001][1001];
int n, m;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
class Data {
public:
	int x, y, left, right;
};

queue <Data> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int left = q.front().left;
		int right = q.front().right;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (map[ny][nx] != '1') {
					Data d;
					if (i == 2 && right >= 1) {
						visit[ny][nx] = 1;
						d.x = nx, d.y = ny, d.left = left, d.right = right - 1;
						q.push(d);
					}
					else if (i == 3 && left >= 1) {
						visit[ny][nx] = 1;
						d.x = nx, d.y = ny, d.left = left - 1, d.right = right;
						q.push(d);
					}
					if (!visit[ny][nx]) {
						if (i == 0 || i == 1) {
							visit[ny][nx] = 1;
							d.x = nx, d.y = ny, d.left = left, d.right = right;
							q.push(d);
						}
					}
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (visit[i][k]) cnt++;
		}
	}

	cout << cnt << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k] == '2') {
				Data d; d.x = k, d.y = i, d.left = l, d.right = r;
				q.push(d);
				visit[i][k] = 1;
			}
		}
	}
	bfs();
}