#include <iostream>
using namespace std;

int arr[101][101];
int main() {
	int n, xpos, ypos, cnt = 0;;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> xpos >> ypos;
		for (int i = ypos; i < ypos + 10; i++) {
			for (int j = xpos; j < xpos + 10; j++) {
				arr[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j] == 1) cnt++;
		}
	}
	cout << cnt << endl;
}