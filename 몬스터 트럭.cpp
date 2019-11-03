#include <iostream>
using namespace std;
char map[51][51];
int p[5];
int r, c;
void check(int x, int y) {
	int cnt = 0;
	for (int i = y; i < y + 2; i++) {
		for (int j = x; j < x + 2; j++) {
			if (map[i][j] == 'X') cnt++;
			if (map[i][j] == '#') return;
		}
	}
	p[cnt]++;
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> map[i];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '.'|| map[i][j] == 'X') {
				if (i + 1 < r && j + 1 < c) {
					check(j, i);
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) cout << p[i] << "\n";
}