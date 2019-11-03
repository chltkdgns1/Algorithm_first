#include <iostream>
using namespace std;
int arr[300000];
int main() {
	int n;
	int cnt = 0;
	arr[1] = 1;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 2; i <= 2*n; i++) {
			int j = 2;
			if (arr[i] == 0) {
				while (1) {
					if (i*j > 2*n) break;
					arr[i*j] = 1;
					j++;
				}
			}
		}
		for (int i = n + 1; i <= 2*n; i++) {
			if (arr[i] == 0) cnt++;
		}
		cout << cnt << endl;
		cnt = 0;
	}
}
