#include <iostream>
using namespace std;

int n, Max = 0;
char map[51][51];

void garo() {
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) { // chk 가로
			if (map[i][j] == map[i][j + 1]) { cnt++; }
			else {
				if (Max < cnt)
					Max = cnt;
				cnt = 1;
			}
		}
	}
}

void sero() {
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) { // chk 세로
			if (map[j][i] == map[j + 1][i]) { cnt++; }
			else {
				if (Max < cnt)
					Max = cnt;
				cnt = 1;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			char tmp = map[i][j];
			map[i][j] = map[i][j + 1];
			map[i][j + 1] = tmp;
			garo();
			sero();
			tmp = map[i][j];
			map[i][j] = map[i][j + 1];
			map[i][j + 1] = tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			char tmp = map[j][i];
			map[j][i] = map[j + 1][i];
			map[j + 1][i] = tmp;
			garo();
			sero();
			tmp = map[j][i];
			map[j][i] = map[j + 1][i];
			map[j + 1][i] = tmp;
		}
	}

	cout << Max << '\n';
	return 0;
