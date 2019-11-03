#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[300][300];
bool check[300][300];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void bfs(int xpos,int ypos) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos });
	check[ypos][xpos] = true;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (x >= 0 && y >= 0 && x < m && y < n) {
				if (map[y][x] > 0 && check[y][x] == false) {
					check[y][x] = true;
					q.push({ x,y });
				}
			}
		}
	}
}
int Go() {
	int result = 1;
	while (1) {
		int m_cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0) {
					m_cnt++;
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int x = j + dx[k];
						int y = i + dy[k];
						if (x >= 0 && y >= 0 && x < m && y < n) {
							if (map[y][x] == 0) cnt++;
						}
					}
					if (map[i][j] - cnt <= 0) map[i][j] = -1;
					else map[i][j] -= cnt;
				}
			}
		}
		int key_cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0 && check[i][j] == false) {
					key_cnt++;
					bfs(j, i);
				}
			}
		}
		if (key_cnt >= 2) return result;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				check[i][j] = false;
				if (map[i][j] == -1) map[i][j] = 0;
			}
		}
		if (m_cnt == 0) return 0;
		result++;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int result;
	if (result = Go()) cout << result << endl;
	else cout << 0 << endl;
}