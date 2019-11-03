#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int map[1001][1001];
bool visit[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, max1;
vector <pair<int, int>> v;
vector <int> e;
bool check(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}

int dfs(int x, int y, int cnt,int ch ) {
	visit[y][x] = 1;
	int t = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check(x, y)) {
			if (!visit[ny][nx] && map[ny][nx] ) {
				map[ny][nx] = ch;
				t += dfs(nx, ny, cnt + 1, ch);
			}
		}
	}
	return t;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k]) v.push_back({ k,i });
		}
	}
	int cnt = 1;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		if (!visit[y][x]) {
			map[y][x] = cnt;
			int s = dfs(x, y, 1, cnt);
			e.push_back(s);
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (!map[i][k]) {
				vector <int> d;
				for (int z = 0; z < 4; z++) {
					int nx = k + dx[z];
					int ny = i + dy[z];
					if (check(nx, ny)) {
						if (map[ny][nx]) {
							if (!d.empty()) d.push_back(map[ny][nx]);
							else {
								bool br = 0;
								for (int i = 0; i < d.size(); i++) {
									if (d[i] == map[ny][nx]) {
										br = 1; break;
									}
								}
								if (!br) d.push_back(map[ny][nx]);
							}
						}
					}
				}
				int t = 1;
				for (int i = 0; i < d.size(); i++) t += e[d[i] - 1];
				if (max1 < t) max1 = t;
			}
		}
	}
	cout << max1 << "\n";
	system("pause");
}
