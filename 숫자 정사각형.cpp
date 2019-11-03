#include <iostream>
#include <math.h>
using namespace std;

char map[51][51];
int n, m;

int Go(int x, int y,char c) {
	int max = 0;
	for (int i = x ; i < m; i++) {
		if (map[y][x] == map[y][i]) {
			if (y + i - x < n) {
				if (map[y][x] == map[y + i - x][x] && map[y][x] == map[y + i - x][i]) {
					int cnt = pow((i - x + 1), 2);
					if (max < cnt) max = cnt;
				}
			}
		}
	}
	return max;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int key = Go(j, i, map[i][j]);
			if (max < key) max = key;
		}
	}
	cout << max << endl;
}