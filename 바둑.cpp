#include <iostream>
#include <string.h>
using namespace std;

char map[15][15];
bool check[15][15];
int a[15], b[15], c[30], d[30];
int n;
void delMap() {
	for (int i = 0; i < n; i++) {
		if (a[i] == 0)
			for (int j = 0; j < n; j++) {
				map[i][j] = '0';
				check[i][j] = true;
			}
	}
	for (int i = 0; i < n; i++) {
		if (b[i] == 0)
			for (int j = 0; j < n; j++) {
				map[j][i] = '0';
				check[i][j] = true;
			}
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == 0) {
			int k = i;
			for (int j = 0; j <= i; j++) { map[j][k] = '0';	k--; check[i][j] = true;}
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i] == 0) {
			int k = i;
			for (int j = n - 1; j >= n - 1 - i; j--) { map[j][k] = '0';	k--; check[i][j] = true;}
		}
	}
}

void scanMap() {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		int xx[15], index = 0;
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1') {
				cnt++;
				xx[index++] = j;
			}
		}
		if (a[i] == cnt) {
			for (int k = 0; k < index; k++) {
				check[i][xx[k]] == true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i] == 0)
			for (int j = 0; j < n; j++) map[j][i] = '0';
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == 0) {
			int k = i;
			for (int j = 0; j <= i; j++) { map[j][k] = '0';	k--; }
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i] == 0) {
			int k = i;
			for (int j = n - 1; j >= n - 1 - i; j--) { map[j][k] = '0';	k--; }
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(map, '1', sizeof(map));
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < 2 * n - 1; i++) cin >> c[i];
	for (int i = 0; i < 2 * n - 1; i++) cin >> d[i];
	delMap();
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
	system("pause");
}