#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int brr[100001];
int n, k;
int Quest(int a, int b, int m) {
	sort(arr + a -1, arr + b );
	return arr[a - 1 + m - 1];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		brr[i] = arr[i];
	}
	for (int i = 0; i < k; i++) {
		int a, b, m;
		cin >> a >> b >> m;
		cout << Quest(a, b, m) << "\n";
		for (int i = 0; i < n; i++) arr[i] = brr[i];
	}
}