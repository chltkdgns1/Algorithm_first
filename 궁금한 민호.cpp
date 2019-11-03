#include <iostream>
using namespace std;
int arr[21][21];
int del[21][21];
int main() {
	int n;
	int a, b, c;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}
	for (int m = 1; m <= n; m++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (m == s || s == e || m == e) continue;
				if (arr[s][e] == arr[s][m] + arr[m][e]) del[s][e] = 1;
				else if (arr[s][e] > arr[s][m] + arr[m][e]) {
					cout << "-1" << endl;
					return 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += !del[i][j] * arr[i][j];
		}
	}
	cout << cnt / 2  << endl;
}