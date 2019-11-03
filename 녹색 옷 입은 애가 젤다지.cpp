#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c = 1;
	while (1) {
		int n;
		cin >> n;
		if (!n) break;
		int map[126][126];
		int d[126][126];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cin >> map[i][j];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) d[i][j] = 1e9;
		}
		d[0][0] = map[0][0];
		queue <pair<int, int>> q;
		q.push({ 0,0 });
		while (!q.empty()) {
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = nx + dx[i];
				int y = ny + dy[i];
				if (x >= 0 && y >= 0 && x < n && y < n) {
					if (d[y][x] > d[ny][nx] + map[y][x] ) {
						d[y][x] = d[ny][nx] + map[y][x];
						q.push({ x,y });
					}
				}
			}
		}
		cout << "Problem "<<c++<<": "<<d[n - 1][n - 1] << "\n";
	}
	system("pause");
}