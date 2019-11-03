#include <iostream>
using namespace std;

char map[21][21];
bool check[21][21];
char load[442];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
int max1 = 0;
void Go(int xpos, int ypos, char ar[], int index) {
	if (max1 < index) max1 = index;
	for (int i = 0; i < 4; i++) {
		int x = xpos + dx[i];
		int y = ypos + dy[i];
		if (x >= 0 && y >= 0 && x < m && y < n) {
			if (check[y][x] == false) {
				bool br = 0;
				for (int j = 0; j < index; j++) {
					if (ar[j] == map[y][x]) { br = 1; break; }
				}
				if (!br) {
					ar[index] = map[y][x];
					check[y][x] = true;
					Go(x, y, ar, index + 1);
					check[y][x] = false;
					ar[index] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	load[0] = map[0][0];
	check[0][0] = true;
	Go(0, 0,load,1);
	cout << max1 << endl;
}