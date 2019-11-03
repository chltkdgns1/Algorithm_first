#include <iostream>
#include <algorithm>
using namespace std;
int arr[50];
int temp_arr[50];
int main() {
	int n;
	while (scanf("%d",&n) != EOF) {
		int k, cnt = 0, check_index = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			temp_arr[i] = arr[i];
		}
		cin >> k;
		sort(arr, arr + n);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (arr[i] == temp_arr[j]) { // 가장 큰 값을 찾음
					if (j - check_index <= k) {
						int temp = temp_arr[j];
						for (int m = j; m > check_index; m--) temp_arr[m] = temp_arr[m - 1];
						temp_arr[check_index] = temp;
						k = k - (j - check_index);
						if (k == 0) {
							for (int i = 0; i < n; i++) cout << temp_arr[i] << " ";
							cout << endl;
							return 0;
						}
						check_index++;
					}
					else {
						break;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) cout << temp_arr[i] << " ";
		cout << endl;
	}
}