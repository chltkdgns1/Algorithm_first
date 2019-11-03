#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
int main() {
	int n, l , cnt = 0;
	double data;
	cin >> n >> l;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) continue;
		else {
			data = double(arr[i]) - 0.5 + l;
			arr[i] = 0;
			for (int j = i + 1; j < n; j++) {
				if (double(arr[j]) + 0.5 <= data) arr[j] = 0;
				else break;
			}
			cnt++;
		}
	}
	cout << cnt << endl;
}