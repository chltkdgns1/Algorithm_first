#include <iostream>
using namespace std;

int arr[500000000];
int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	int cnt = 0;
	for (int i = 2; i <= 50000000; i++) {
		int k = 2;
		if (!arr[i]) {
			cnt++;
			if (cnt == n) {
				cout << i << "\n";
				break;
			}
			while (i*k <= 50000000) {
				arr[i*k] = 1;
				k++;
			}
		}
	}
}