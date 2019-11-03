#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char map[25][25];
bool check[25][25];
int key_data[1000];
int index;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1 ,-1 };
int n;
void bfs(int xpos, int ypos) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos });
	check[ypos][xpos] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (check[ny][nx] == false && map[ny][nx] == '1') {
					cnt++;
					map[ny][nx] = '0';
					check[ny][nx] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	key_data[index++] = cnt;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1') bfs(j, i);
		}
	}
	sort(key_data, key_data + index);
	cout << index << endl;
	for (int i = 0; i < index; i++) cout << key_data[i] << endl;
}