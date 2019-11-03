#include <iostream>
#include <queue>
using namespace std;

queue <pair<int, int>> q;
int map[50][50];
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
int w, h;
void Go(int xpos,int ypos) {
	q.push(make_pair(xpos, ypos));
	while (!q.empty()) {
		int x1, y1;
		x1 = q.front().first;
		y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int x, y;
			x = x1 + dx[i];
			y = y1 + dy[i];
			if (x >= 0 && y >= 0 && x < w && y < h) {
				if (map[y][x] == 1) {
					q.push(make_pair(x, y));
					map[y][x] = 0;
				}
			}
		}
	}
}
int main() {
	while (1) {
		int cnt = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) cin >> map[i][j];
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					Go(j, i);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) map[i][j] = 0;
		}
	}
}