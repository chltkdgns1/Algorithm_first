#include <iostream>
using namespace std;
int arr[600][600]; // 배열 B
int arr2[300][300]; // 배열 A
int check[600][600]; // 겹치는 부분 확인
int main() {
	int H, W, X, Y;
	cin >> H >> W >> X >> Y;
	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> arr[i][j];
			if (X <= i && i < H && Y <= j && j < W) check[i][j] = 1;
			else check[i][j] = 0;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (check[i][j] == 0) arr2[i][j] = arr[i][j];
			else {
				arr2[i][j] = arr[i][j] - arr2[i - X][j - Y];
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}