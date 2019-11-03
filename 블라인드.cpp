#include <iostream>
using namespace std;
char map[1000][1000];
int check[5];
void checkCur(int x,int y) {
	int cnt = 0;
	for (int i = y; i < y + 4; i++) {
		for (int j = x; j < x + 4; j++) {
			if (map[i][j] == '*') cnt++;
		}
	}
	check[cnt / 4]++;
}
int main() {
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < 5 * m + 1; i++) cin >> map[i];
	int x = 1, y = 1;
	for (int i = 0; i < m; i++ ) {
		for (int j = 0; j < n ; j++) {
			checkCur(x + j * 5, y + i * 5);
		}
	}
	for (int i = 0; i < 5; i++) cout << check[i] << " ";
}