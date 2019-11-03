#include <iostream>
using namespace std;

int arr[100];
int d[100];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int max = -1, min = 987654321;
		for (int i = 0; i < n; i++) {
			if (max < arr[i]) max = arr[i];
		}

		int k = 0;
		for (int i = 0; i < n; i++) {
			if (max == arr[i]) {
				arr[i] = -987654321;
				d[i] = cnt;
				k++;
			}
		}
		cnt += k;
	}

	for (int i = 0; i < n; i++) cout << d[i] << " ";
	cout << "\n";

	system("pause");
}