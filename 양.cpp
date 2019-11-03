#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int>> v;
char map[251][251];
bool visit[251][251];
int wolf, moo;
int t_wolf, t_moo;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int r, c;

void dfs(int x,int y) {
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < c && ny >= 0 && ny < r) {
			if (!visit[ny][nx] && map[ny][nx] != '#') {
				if (map[ny][nx] == 'o') moo++;
				else if (map[ny][nx] == 'v') wolf++;
				dfs(nx, ny);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			cin >> map[i][k];
			if (map[i][k] == 'v' || map[i][k] == 'o') {
				v.push_back({ k,i });
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		if (!visit[y][x]) {
			if (map[y][x] == 'o') moo++;
			else wolf++;
			dfs(x, y);
			if (wolf < moo) t_moo += moo;
			else t_wolf += wolf;
			wolf = 0, moo = 0;
		}
	}
	cout << t_moo << " " << t_wolf << "\n";
}