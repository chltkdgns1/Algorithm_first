#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char map[50][50];
bool check[50][50];
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int len_data[1000];
int len_index;
void bfs(int xpos, int ypos) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos });
	check[ypos][xpos] = true;
	int cnt = 0;
	while (1) {
		int len = q.size();
		if (len == 0) {
			len_data[len_index++] = cnt - 1;
			return;
		}
		for (int i = 0; i < len; i++) {
			int x1 = q.front().first;
			int y1 = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = x1 + dx[i];
				int y = y1 + dy[i];
				if (x >= 0 && y >= 0 && x < m && y < n) {
					if (map[y][x] == 'L' && check[y][x] == false) {
						check[y][x] = true;
						q.push({ x,y });
					}
				}
			}
		}
		cnt++;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				bfs(j, i);
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) check[i][j] = false;
				}
			}
		}
	}
	sort(len_data, len_data + len_index);
	cout << len_data[len_index - 1] << endl;
}