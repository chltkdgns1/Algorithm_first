#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
bool data_arr[500001];

bool binarySearch(int n, int left,int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (arr[middle] == n) return true;
		else if (arr[middle] < n) left = middle + 1;
		else right = middle - 1;
	}
	return false;
}

int main() {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int m , ca;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ca;
		cout << binarySearch(ca, 0, n - 1) << " ";
	}
}