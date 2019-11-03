#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };

pair<int, int> xy[2];
int map[51][51];
int r, c, t, cnt = 0;

bool check(int x, int y) {
	if (x >= 0 && x < c && y >= 0 && y < r) return true;
	return false;
}

void windcuter() {
	int a = xy[0].first, b = xy[0].second, c = xy[1].first, d = xy[1].second;
	int dir = 0;
	int dix[4] = { -1,0,1,0 }, diy[4] = { 0,1,0,-1 };
	while (1) { // 위쪽
		int x = a + dx[dir];
		int y = b + dy[dir];
		if (map[y][x] == -1) break;
		if(check(x,y) && xy[0].second >= y){
			if (map[y][x] > 0) {
				if (map[b][a] == -1) map[y][x] = 0;
				else {
					map[b][a] = map[y][x];
					map[y][x] = 0;
				}
			}
			a = x;
			b = y;
		}
		else {
			dir++;
			if (dir == 4) dir = 0;
		}
		
	}
	dir = 0;
	while (1) { // 아래쪽
		int x = c + dix[dir];
		int y = d + diy[dir];
		if (map[y][x] == -1) break;
		if (check(x, y) && xy[1].second <= y) {
			if (map[y][x] > 0) {
				if (map[d][c] == -1) map[y][x] = 0;
				else {
					map[d][c] = map[y][x];
					map[y][x] = 0;
				}
			}
			c = x;
			d = y;
		}
		else {
			dir++;
			if (dir == 4) dir = 0;
		}
	}
}

void dustMove() {
	vector <pair<pair<int, int>, int>> v;
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			if (map[i][k] > 0) {
				int cnt = 0;
				for (int z = 0; z < 4; z++) {
					int nx = k + dx[z];
					int ny = i + dy[z];
					if (check(nx, ny)) {
						if (map[ny][nx] != -1) {
							cnt++;
							v.push_back({ {nx,ny} ,map[i][k] / 5 });
						}
					}
				}
				map[i][k] -= cnt * (map[i][k] / 5);
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first.first;
		int y = v[i].first.second;
		int d = v[i].second;
		map[y][x] += d;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			cin >> map[i][k];
			if (map[i][k] == -1) {
				xy[cnt].first = k, xy[cnt].second = i;
				cnt++;
			}
		}
	}
	for (int i = 0; i < t; i++) {
		dustMove();
		windcuter();
	}
	int t = 0;
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			if (map[i][k] > 0) t += map[i][k];
		}
	}
	cout << t << "\n";
}