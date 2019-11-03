#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int map[100][100];
bool check[100][100];
int data_arr[10000];
int data_index = 1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs(int xpos, int ypos) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos });
	check[ypos][xpos] = false;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (x >= 0 && y >= 0 && x < n && y < n) {
				if (check[y][x] == true) {
					q.push({ x,y });
					check[y][x] = false;
				}
			}
		}
	}
}
int main() {
	cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (max < map[i][j]) max = map[i][j];
		}
	}
	data_arr[0] = 1;
	for (int k = 1; k <= max; k++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > k) check[i][j] = true;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == true) {
					bfs(j, i);
					cnt++;
				}
			}
		}
		data_arr[data_index++] = cnt;
	}
	sort(data_arr, data_arr + data_index);
	cout << data_arr[data_index - 1] << endl;
}