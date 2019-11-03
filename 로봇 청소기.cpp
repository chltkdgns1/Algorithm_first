#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

char map[21][21];
bool visit[21][21];

int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int n, m;
int dt[12][12];

class Data {
public:
	int x, y, d;
};

void bfs(int x, int y,int t) {
	visit[y][x] = 1;
	queue <Data> q;
	q.push({ x,y, 0 });
	while (!q.empty()) {
		Data d = q.front();
		int x = d.x, y = d.y, dis = d.d;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				int w = map[ny][nx];
				if (w != 'x' && !visit[ny][nx]) {
					visit[ny][nx] = 1;
					if (w >= 1 && w <= 11 && t != w) dt[t][w] = dis + 1;
					q.push({ nx,ny,dis + 1 });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);

	while (1) {
		cin >> m >> n;
		if (!m && !n) break;
		memset(map, 0, sizeof(map));
		
		for (int i = 0; i <= 11; i++) {
			for (int k = 0; k <= 11; k++) {
				if (i == k) dt[i][k] = 0;
				else dt[i][k] = 987654321;
			}
		}
		int cnt = 1;
		int x, y;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][k];
				if (map[i][k] == 'o') {
					x = k, y = i;
					map[i][k] = 0;
				}
				else if (map[i][k] == '*') {
					map[i][k] = cnt++;
					v.push_back({ k,i });
				}
			}
		}

		int t = 1;
		memset(visit, 0, sizeof(visit));
		bfs(x, y, 0);
		for (auto a : v) {
			memset(visit, 0, sizeof(visit));
			bfs(a.first, a.second, t++);
		}

		vector <int> e; 
		for (int i = 1; i < cnt; i++) e.push_back(i);

		long long res = 987654321;
		do {
			long long t = 0, dis = 0;
			for (auto a : e) {
				dis += dt[t][a];
				t = a;
			}
			res = res > dis ? dis : res;
		} while (next_permutation(e.begin(), e.end()));

		if (res >= 987654321) cout << -1 << "\n";
		else cout << res << "\n";
	}
}