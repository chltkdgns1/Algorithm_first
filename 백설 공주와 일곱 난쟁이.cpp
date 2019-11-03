#include <iostream>
using namespace std;
int arr[9];
int main() {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = arr[j] = -1;
				for (int i = 0; i < 9; i++) {
					if (arr[i] != -1) cout << arr[i] << endl;
				}
			}
		}
	}
}