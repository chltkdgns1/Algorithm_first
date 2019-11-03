#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char map[1001][1001];
bool p_visit[1001][1001];
bool f_visit[1001][1001];
int x, y, dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int n, m;
vector <pair<int, int>> v;
bool check(int x, int y) {
	if (x >= 0 && y >= 0 && x < m && y < n) return true;
	return false;
}
void bfs(int x, int y) {
	p_visit[y][x] = 1;
	queue <pair<int, int>> pq, fq;
	pq.push({ x,y });
	for (int i = 0; i < v.size(); i++) {
		f_visit[v[i].second][v[i].first] = 1;
		fq.push({ v[i].first,v[i].second });
	}
	int cnt = 0;
	while (1) {
		int len1 = pq.size();
		int len2 = fq.size();
		if (!len1 ) break;
		for (int i = 0; i < len2; i++) {
			int nx = fq.front().first;
			int ny = fq.front().second;
			fq.pop();
			for (int i = 0; i < 4; i++) {
				int x = nx + dx[i];
				int y = ny + dy[i];
				if (check(x, y)) {
					if (!f_visit[y][x] && map[y][x] != '#') {
						f_visit[y][x] = 1;
						map[y][x] = 'F';
						fq.push({ x,y });
					}
				}
			}
		}
		for (int i = 0; i < len1; i++) {
			int nx = pq.front().first;
			int ny = pq.front().second;
			if (!nx || !ny || nx == m - 1 || ny == n - 1) {
				cout << cnt + 1 << "\n";
				return;
			}
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int x = nx + dx[i];
				int y = ny + dy[i];
				if (check(x, y)) {
					if (map[y][x] == '.' && !p_visit[y][x]) {
						p_visit[y][x] = 1;
						pq.push({ x,y });
					}
				}
			}
		}
		cnt++;
	}
	cout << "IMPOSSIBLE" << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k] == 'J') x = k, y = i; // »ç¶÷
			if (map[i][k] == 'F') v.push_back({ k,i }); // ºÒ
		}
	}
	bfs(x, y);
}