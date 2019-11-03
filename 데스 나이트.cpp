#include <iostream>
#include <queue>
using namespace std;

bool visit[201][201];
queue <pair<pair<int, int>, int>> q;
int dx[6] = { -2,-2,0,0,2,2 }, dy[6] = { -1,1,-2,2,-1,1 };
int n, r2, c2;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if (x == r2 && y == c2) {
			cout << d << "\n";
			return;
		}
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!visit[ny][nx]) {
					visit[ny][nx] = 1;
					q.push({ {nx,ny},d + 1 });
				}
			}
		}
	}
	cout << -1 << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int r1, c1; cin >> r1 >> c1 >> r2 >> c2;
	visit[c1][r1] = 1;
	q.push({ {r1,c1},0 });
	bfs();
}