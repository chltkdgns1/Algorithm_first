#include <iostream>
#include <queue>
using namespace std;

int n,m;
int key;
char map[1001][1001];
bool check[1001][1001];
bool check2[1001][1001];
int dx[4] = { 1,-1 ,0,0};
int dy[4] = { 0,0,1,-1};
class posData {
public:
	int xpos, ypos;
	int hit;
};
posData d;
void bfs(int xpos, int ypos) {
	d.xpos = xpos, d.ypos = ypos;
	queue <posData> q;
	q.push(d);
	check[ypos][xpos] = true;
	int cnt = 1;
	while (1) {
		int len = q.size();
		if (len == 0) return;
		for (int i = 0; i < len; i++) {
			// 벽이 있는 곳을 부시고 간 경우와 안 부시고 간 경우
			int x1 = q.front().xpos;
			int y1 = q.front().ypos;
			int hit = q.front().hit;
			q.pop();
			if (x1 == m - 1 && y1 == n - 1) {
				key = cnt ;
				return;
			}
			for (int i = 0; i < 4; i++) {
				int x = x1 + dx[i];
				int y = y1 + dy[i];
				if (x >= 0 && y >= 0 && x < m && y < n) {
					if (hit == 1) {
						if (map[y][x] == '0' && check[y][x] == false && check2[y][x] == false) {
							check2[y][x] = true;
							posData t_d;
							t_d.xpos = x, t_d.ypos = y, t_d.hit = hit;
							q.push(t_d);
						}
					}
					else {
						if (map[y][x] == '0' && check[y][x] == false ) {
							check[y][x] = true;
							posData t_d;
							t_d.xpos = x, t_d.ypos = y, t_d.hit = hit;
							q.push(t_d);
						}
						if (map[y][x] == '1' && check[y][x] == false) {
							check[y][x] = true;
							posData t_d;
							t_d.xpos = x, t_d.ypos = y, t_d.hit = 1;
							q.push(t_d);
						}
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
	bfs(0, 0);
	if (key) cout << key << endl;
	else cout << -1 << endl;
}