#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long arr[1000001];
int binarySearch(long long b[],long long number, int left, int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (b[middle] == number) {
			return middle;
		}
		if (b[middle] < number) {
			left = middle + 1;
		}
		else if (b[middle] > number) {
			right = middle - 1;
		}
	}
	return -1;
}
int main() {//    0 1 2 3 4 5 6 7 8 9 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long x;
	while (cin >> x) {
		int br = 0;
		x = x * 10000000;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			int index = binarySearch(arr, x - arr[i], 0, n - 1);
			if (index != -1 && index != i) {
				cout << "yes " << arr[i] << " " << x - arr[i] << "\n";
				br = 1;
				break;
			}
		}
		if (br == 0) cout << "danger" << "\n";
		br = 0;
		for (int i = 0; i < n; i++) arr[i] = 0;
	}
}