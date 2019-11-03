#include <iostream>
using namespace std;

int arr[100];
int main() {
	int n, m;
	int temp = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {	
				if (arr[i] + arr[j] + arr[k] <= m) {
					if (arr[i] + arr[j] + arr[k] == m) {
						cout << arr[i] + arr[j] + arr[k] << endl;
						return 0;
					}
					if (temp < (arr[i] + arr[j] + arr[k])) {
						temp = arr[i] + arr[j] + arr[k];
					}
				}
			}
		}
	}
	cout << temp << endl;
	system("pause");
}

