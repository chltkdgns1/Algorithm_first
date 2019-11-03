#include <iostream>
using namespace std;
int arr[100][100];
int main() {
	int h, w;
	char c;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> c;
			if (c == '.') arr[i][j] = -1;
			else if (c == 'c') arr[i][j] = 0;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 0) {
				int cnt = 1;
				for (int k = j + 1; k < w; k++) {
					if (arr[i][k] != 0) {
						arr[i][k] = cnt;
						cnt++;
					}
					else break;
				}
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}