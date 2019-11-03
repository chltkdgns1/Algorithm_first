#include <iostream>
#include <algorithm>
using namespace std;

long long arr[10001];
int main() {
	long long k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> arr[i];
	sort(arr, arr + k);
	long long  left = 0, right = arr[k - 1];
	long long  middle;
	long long  max = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) cnt += arr[i] / middle;
		if (cnt < n) {
			right = middle  - 1;
		}
		else {
			left = middle + 1;
			if (middle > max) max = middle;
		}
	}
	cout <<max<< endl;
}