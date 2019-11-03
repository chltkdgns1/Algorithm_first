#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;

char map[51][51];
bool visit[51][51];
int n, m, dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int dis[8][8];

class Data {
public:
	int x, y, cnt;
};
vector <Data> v;
void bfs(int x, int y) {
	memset(visit, 0, sizeof(visit));
	visit[y][x] = 1;
	queue <Data> q;
	q.push({x,y,0});

	while (!q.empty()) {
		int xx = q.front().x, yy = q.front().y, k = q.front().cnt;
		q.pop();
		if (map[yy][xx] != '#' && map[yy][xx] != '.') {
			int a = map[yy][xx], b = map[y][x];
			dis[b][a] = dis[a][b] = k;
		}
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (!visit[ny][nx] && map[ny][nx] != '#') {
					q.push({ nx,ny,k + 1 });
					visit[ny][nx] = 1;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
	cin >> m >> n;
	vector<pair<int, int>> ve;
	vector <int> e;
	int cnt = 1, x, y;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			char a = map[i][k];
			if (a == 'S') map[i][k] = 0, ve.push_back({ k,i });
			else if(a == 'X') ve.push_back({ k,i }), map[i][k] = cnt++;
			else if (a == 'E') map[i][k] = 6;
		}
	}
	for (int i = 1; i < cnt; i++) e.push_back(i);
	for (auto a : ve) bfs(a.first, a.second);

	int res = 987654321;
	do {
		int s = 0, cnt = 0;
		for (int i = 0; i < e.size(); i++) {
			int t = e[i];
			cnt += dis[s][t];
			s = t;
		}
		cnt += dis[s][6];
		res = min(res, cnt);
	} while (next_permutation(e.begin(), e.end()));

	cout << res << "\n";
}