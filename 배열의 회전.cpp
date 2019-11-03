#include <iostream>
using namespace std;

int arr[10][10];

void rotation() {
	int brr[10][10];
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			brr[k][9 - i] = arr[i][k];
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			arr[i][k] = brr[i][k];
			cout << arr[i][k] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int cnt = 1;
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			arr[i][k] = cnt++;
		}
	}
	rotation();
	rotation();
	rotation();
	rotation();
	system("pause");
}