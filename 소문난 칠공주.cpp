#include <iostream>
#include <string>
#include <queue>
using namespace std;
char map[6][6];
char t_map[6][6];
char t_check[6][6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt, s_cnt;
int check(int xpos,int ypos) {
	int total = 1;
	for (int i = 0; i < 4; i++) {
		int x = xpos + dx[i], y = ypos + dy[i];
		if (x >= 0 && y >= 0 && x < 5 && y < 5) {
			if (t_map[y][x] != 0 && t_check[y][x] == false) {
				cout << "c";
				t_check[y][x] = true;
				if (t_map[y][x] == 'S') s_cnt++;
				total += check(x, y);
			}
		}
	}
	return total;
}
void dfs(int x,int y,int idx) {
	if (idx == 7) {
		s_cnt = 0;
		int x, y;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (t_map[i][j])  x = j, y = i; 
				t_check[i][j] = false;
			}
		}
		if (check(x, y) == 7 && s_cnt >= 4) { cout << "a"; cnt++; }
		return;
	}
	if (x == 5) dfs(0, y + 1, idx);
	if (y == 5) return;
	t_map[y][x] = map[y][x];
	dfs(x + 1, y, idx + 1);
	t_map[y][x] = 0;
	dfs(x + 1, y, idx);
}
int main() {
	for (int i = 0; i < 5; i++) cin >> map[i];
	dfs(0, 0, 0);
	cout << cnt << "\n";
	system("pause");
}