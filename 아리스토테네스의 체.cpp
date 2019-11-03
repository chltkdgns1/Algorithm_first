#include <iostream>
using namespace std;
int arr[1001];
int main() {
	int n, k;
	int cnt = 0;
	cin >> n >> k;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		int j = 1;
		if (arr[i] == 0) {
			while (1) {
				if (i*j > n) break;
				if (arr[i*j] == 1) {
					j++;
					continue;
				}
				arr[i*j] = 1;
				cnt++;
				if (cnt == k) {
					cout << i*j << endl;
					return 0;
				}
				j++;
			}
		}
	}
}