#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int main() {
	int n , total = 0,max=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (max < arr[i] * (n - i)) max = arr[i] * (n - i);
	}
	cout << max << endl;
}