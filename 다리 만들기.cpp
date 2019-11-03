#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int n;
int map[100][100];
char check[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
class landData {
public:
	int xpos, ypos, key;
};
landData d[10000];
int len_index;
void bfs(int xpos, int ypos,int cnt) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos });
	check[ypos][xpos] = true;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		int cnt1 = 0;
		for (int i = 0; i < 4; i++) {
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (x >= 0 && y >= 0 && x < n && y < n) {
				if (map[y][x] == 1 && check[y][x] == false) {
					check[y][x] = true;
					q.push({ x,y });
				}
				if (map[y][x] == 0)  cnt1++;
			}
		}
		if (cnt1 != 0) {
			d[len_index].xpos = x1, d[len_index].ypos = y1; d[len_index].key = cnt;
			len_index++;
		}
	}
}
int main() {
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> map[i][j];
	}
	int cnt = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] == false) {
				bfs(j, i, cnt);
				cnt++;
			}
		}
	}
	int min = 10000;
	for (int i = 0; i < len_index; i++) {
		for (int j = 0; j < len_index; j++) {
			if (i != j && d[i].key != d[j].key) {
				if (min > abs(d[i].xpos - d[j].xpos) + abs(d[i].ypos - d[j].ypos) - 1) {
					min = abs(d[i].xpos - d[j].xpos) + abs(d[i].ypos - d[j].ypos) - 1;
				}
			}
		}
	}
	cout << min << endl;
}