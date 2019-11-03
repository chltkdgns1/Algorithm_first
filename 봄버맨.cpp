#include <iostream>
#include <vector>
using namespace std;

int map[205][205];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector <pair<int, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r, c, n;
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			char ch;
			cin >> ch;
			if (ch == 'O') map[i][k] = 0;
			else if (ch == '.') map[i][k] = -1;
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < r; i++) {
			for (int k = 0; k < c; k++) {
				if (map[i][k] >= 0) {
					map[i][k]++;
					if (map[i][k] == 3) {
						map[i][k] = -1;
						v.push_back({ k,i });
					}
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			for (int k = 0; k < 4; k++) {
				int x = v[i].first + dx[k], y = v[i].second + dy[k];
				if (x >= 0 && y >= 0 && x < c && y < r) map[y][x] = -1;
			}
		}
		if (j % 2 == 1) {
			for (int i = 0; i < r; i++) {
				for (int k = 0; k < c; k++) {
					if (map[i][k] == -1) map[i][k] = 0;
				}
			}
		}
		v.clear();
	}
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			if (map[i][k] >= 0) cout << "O";
			else if (map[i][k] == -1) cout << ".";
		}
		cout << "\n";
	}
}