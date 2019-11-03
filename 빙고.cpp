#include <iostream>
#include <map>
#include <string.h>
using namespace std;
class Data {
public:
	int x, y;
};
map <int, Data> m;
int board[6][6];
int dx[8] = { 0,0,1,-1,1,-1,-1,1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int d[4], res;
bool visit[6][6];
bool check(int x, int y) {
	if (x >= 0 && x < 5 && y >= 0 && y < 5) return true;
	return false;
}
void go(int x, int y, int dir) {
	if (!dir || dir == 1) d[0]++;
	else if (dir == 2 || dir == 3) d[1]++;
	else if (dir == 4 || dir == 5) d[2]++;
	else d[3]++;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (check(nx, ny) && !visit[ny][nx] && board[ny][nx] == -1) {
		visit[ny][nx] = 1;
		go(nx, ny, dir);
	}
}
void dfs(int x,int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny) && board[ny][nx] == -1) {
			visit[ny][nx] = 1;
			go(nx, ny, i);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			cin >> board[i][k];
			m[board[i][k]] = { k,i };
		}
	}
	int cnt = 0;
	bool check = 0;
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			int a; cin >> a;
			if (!check) {
				cnt++;
				board[m[a].y][m[a].x] = -1;
				memset(visit, 0, sizeof(visit));
				memset(d, 0, sizeof(d));
				dfs(m[a].x, m[a].y);
				for (int i = 0; i < 4; i++) if (d[i] == 4) res++;
				if (res >= 3) check = 1;
			}
		}
	}
	cout << cnt << "\n";
}