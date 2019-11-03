#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n , m , data;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> data;
		int a = (lower_bound(arr, arr + n, data) - arr);
		int b = upper_bound(arr, arr + n, data) - arr;
		cout << b - a << " ";
	}
}