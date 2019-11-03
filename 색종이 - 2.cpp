#include <iostream>
using namespace std;

int map[101][101];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int i = b; i < b + 10; i++) {
			for (int k = a; k < a + 10; k++) {
				map[i][k] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		for (int k = 0; k <= 100; k++) {
			if (map[i][k]) {
				for (int a = 0; a < 4; a++) {
					int x = k + dx[a];
					int y = i + dy[a];
					if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
						if (!map[y][x]) cnt++;
					}
				}
			}
		}
	}
	cout << cnt << "\n";
}