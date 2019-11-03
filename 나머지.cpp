#include <iostream>
using namespace std;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1};
int arr[100][100];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k= 1,dir = 0;
	int n, m; cin >> n >> m;
	int x = 0, y = 0;
	while (k <= n * m) {
		arr[y][x] = k++;
		x += dx[dir], y += dy[dir];
		if ((x < 0 || y < 0 || x >= m || y >= n) || arr[y][x]) {
			x -= dx[dir]; y -= dy[dir];
			dir++;
			dir %= 4;
			x += dx[dir], y += dy[dir];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			printf("%5d", arr[i][k]);
		}
		cout << "\n";
	}
	system("pause");
}
	
