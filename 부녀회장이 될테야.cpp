#include <iostream>
using namespace std;

int main() {
	int array[15][15];
	int test_case;
	int k, n;
	cin >> test_case;
	for (int i = 0; i < 14; i++) array[0][i] = i + 1;
	for (int i = 0; i < test_case; i++) {
		cin >> k;
		cin >> n;
		for (int j = 0; j < k  ; j++) {
			for (int m = 0; m < n; m++) {
				if (m == 0) {
					array[j + 1][m] = 1;
					continue;
				}
				array[j + 1][m] = array[j][m] + array[j + 1][m - 1];
			}
		}
		cout << array[k ][n - 1] << endl;
	}
}