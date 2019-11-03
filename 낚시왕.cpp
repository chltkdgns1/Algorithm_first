#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int dx[4] = { 0,0,1,-1 }, dy[4] = { -1,1,0,0 };
class shark {
public:
	int c, d, e;
	bool br;
	shark(int c, int d, int e, int br) :c(c), d(d), e(e), br(br) { }
};
class Map {
public:
	deque <shark> v;
};
Map map[101][101];
int total_size;
int n, k, m;
bool cmp(const shark &a, const shark &b) {
	return a.e < b.e;
}
void fishing(int x) { // 매개변수 렬 값
	for (int i = 1; i <= n; i++) {
		if (map[i][x].v.size()) {
			total_size += map[i][x].v.front().e;
			map[i][x].v.pop_front();
			break;
		}
	}
}
void go(int x, int y, shark &s) {
	int dir = s.d;
	int sp = s.c;
	int nx = x, ny = y;
	while (sp) {
		switch (dir) {
		case 0:
			if (ny - 1 <= sp) sp -= (ny - 1), dir += 1, ny = 1;
			else ny -= sp, sp = 0;
			break;
		case 1:
			if (n - ny <= sp) sp -= (n - ny), dir -= 1, ny = n;
			else ny += sp, sp = 0;
			break;
		case 2:
			if (k - nx <= sp) sp -= (k - nx), dir += 1, nx = k;
			else nx += sp, sp = 0;
			break;
		case 3:
			if (nx - 1 <= sp) sp -= (nx - 1), dir -= 1, nx = 1;
			else nx -= sp, sp = 0;
			break;
		}
	}
	map[ny][nx].v.push_back(shark(s.c, dir, s.e, 1));
}
void moveShark() {
	for (int i = 1; i <= n; i++) {
		for (int z = 1; z <= k; z++) {
			if (map[i][z].v.size()) {
				if (!map[i][z].v.front().br) {
					go(z, i, map[i][z].v.front());
					map[i][z].v.pop_front();
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int z = 1; z <= k; z++) {
			if (map[i][z].v.size()) {
				sort(map[i][z].v.begin(), map[i][z].v.end(), cmp);
				while (map[i][z].v.size() != 1) {
					map[i][z].v.pop_front();
				}
				map[i][z].v.front().br = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		map[a][b].v.push_back(shark(c, d - 1, e, 0));
	}

	for (int i = 1; i <= k; i++) {
		fishing(i);
		moveShark();
	}
	cout << total_size << "\n";
}