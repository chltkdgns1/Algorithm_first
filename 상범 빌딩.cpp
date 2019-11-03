#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

char map[31][31][31];
bool check[31][31][31];
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
int x2, y2, h2, x1, yy1, h1;
int l, r, c;
class Data {
public:
	int x, y, h;
};
Data d;
void bfs() {
	queue <Data> q;
	d.x = x1, d.y = yy1, d.h = h1;
	q.push(d);
	int cnt = 0;
	while (1) {
		int len = q.size();
		if (len == 0) {
			cout << "Trapped!" << "\n";
			return;
		}
		for (int i = 0; i < len; i++) {
			int nx = q.front().x;
			int ny = q.front().y;
			int nh = q.front().h;
			if (nx == x2 && ny == y2 && nh == h2) {
				cout <<"Escaped in "<< cnt<<" minute(s)." << "\n";
				return;
			}
			q.pop();
			for (int i = 0; i < 6; i++) {
				int x = nx+ dx[i];
				int y = ny + dy[i];
				int h = nh + dh[i];
				if (x >= 0 && y >= 0 && h >= 0 && x < c && y < r && h < l) {
					if (check[h][y][x] == false && map[h][y][x] != '#') {
						check[h][y][x] = true;
						d.x = x, d.y = y, d.h = h;
						q.push(d);
					}
				}
			}
		}
		cnt++;
	}
}
int main() {
	while (1) {
		cin >> l >> r >> c;
		int a = 0, b = 0;
		if (l == 0 && r == 0 && c == 0) break;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> map[i][j];
				if (a && b) continue;
				for (int k = 0; k < c; k++) {
					if (map[i][j][k] == 'S') { a++; x1 = k, yy1 = j, h1 = i; }
					if (map[i][j][k] == 'E') { b++; x2 = k, y2 = j, h2 = i; }
				}
			}
		}
		bfs();
		memset(check, 0, sizeof(check));
	}
}