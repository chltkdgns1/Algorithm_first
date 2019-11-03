#include <iostream>
#include <queue>
using namespace std;

int map[300][300];
bool check[300][300];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { -2,-1,1,2,-2,-1,1,2 };
int len , key;
void bfs(int xpos, int ypos) {
	queue <pair<int, int>> q;
	q.push({ xpos,ypos });
	check[ypos][xpos] = true;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (x >= 0 && y >= 0 && x < len && y < len) {
				if(map[y][x] == -1) {
					key = map[y1][x1] + 1;
					return;
				}
				if (map[y][x] == 0 && check[y][x] == false) {
					map[y][x] = map[y1][x1] + 1;
					check[y][x]= true;
					q.push({ x,y });
				}
			}
		}
	}
}
int main() {
	int x1,y1,x2,y2,t;
	cin >> t;
	while (t--) {
		cin >>len>> x1 >> y1 >> x2 >> y2;
		map[y2][x2] = -1;
		if (x1 == x2 && y1 == y2) {
			cout << 0 << endl;
			continue;
		}
		bfs(x1, y1);
		cout << key << endl;
		key = 0;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				map[i][j] = check[i][j] = 0;
			}
		}
	}
}