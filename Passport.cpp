#include <iostream>
using namespace std;

bool SameNumber(int *array);
int w, n;

int main() {
	int *array;
	cin >> w;
	cin >> n;
	if (10 <= w && w <= 799994 && 4 <= n && n <= 5000) {
		array = new int[n+1];
		for (int i = 0; i < n; i++) {
			cin >> array[i];
			if (1 <= array[i] && array[i] <= 200000);
			else {
				cout << "No" << endl;
				//system("pause");
				return 0;
			}
		}

		if (SameNumber(array)) {
			for (int i = 0; i < n - 3; i++) {
				for (int j = i + 1; j < n - 2; j++) {
					for (int m = j + 1; m < n - 1; m++) {
						for (int l = m + 1; l < n; l++) {
							if (array[i] + array[j] + array[m] + array[l] == w) {
								cout << "Yes" << endl;
								//system("pause");
								return 0;
							}
						}
					}
				}
			}
			cout << "No" << endl;
			//system("pause");
		}
		else {
			cout << "No" << endl;
			//system("pause");
			return 0;
		}
	}
}

bool SameNumber(int *array) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (array[i] == array[j]) {
				return false;
			}
		}
	}
	return true;
}