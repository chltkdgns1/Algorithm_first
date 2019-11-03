#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
char arr[100][100];
char k_arr[5];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m, k, cnt;
void Go(int xpos, int ypos,int index) {
	int x1, y1, x, y;
	queue <pair<int, int>> q;
	char c = NULL;
	q.push(make_pair(xpos, ypos));
	while (!q.empty()) {
		x1 = q.front().first;
		y1 = q.front().second;
		q.pop();
		if (c != arr[y1][x1]) {
			index++;
			c = arr[y1][x1];
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j < 4; j++) {
				x = x1 + dx[j] * i;
				y = y1 + dy[j] * i;
				if (x >= 0 && y >= 0 && x < m && y < n) {
					if (arr[y][x] == k_arr[index]) {
						if (index == strlen(k_arr) - 1) cnt++;
						else q.push(make_pair(x, y));
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> k_arr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (k_arr[0] == arr[i][j]) {
				Go(j, i , 0);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}



