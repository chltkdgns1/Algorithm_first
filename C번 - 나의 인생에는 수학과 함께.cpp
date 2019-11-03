#include <iostream>
using namespace std;

char map[6][6];
int dx[2] = { 0,1 }, dy[2] = { 1,0 };
int n;
bool visit[6][6];
int res1 = 987654321, res2 = -987654321;
void dfs(int x,int y,int data,char sign){
	if (x == n - 1 && y == n - 1) {
		if (res1 > data) res1 = data;
		if (res2 < data) res2 = data;
		return;
	}
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (!visit[ny][nx]) {
				visit[ny][nx] = 1;
				if (map[ny][nx] >= 48 && map[ny][nx] <= 53) {
					if (sign != 0) {
						if (sign == '+') dfs(nx, ny, data + map[ny][nx] - 48, 0);
						else if (sign == '-') dfs(nx, ny, data - (map[ny][nx] - 48), 0);
						else dfs(nx, ny, data * (map[ny][nx] - 48), 0);
					}
					else dfs(nx, ny, map[ny][nx] - 48, 0);
				}
				else dfs(nx, ny, data, map[ny][nx]);
				visit[ny][nx] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> map[i][k];
		}
	}
	visit[0][0] = 1;
	dfs(0, 0, map[0][0] - 48, 0);
	cout << res2 << " " << res1 << "\n";
}