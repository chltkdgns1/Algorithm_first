#include <iostream>
#include <algorithm>
using namespace std;
long long arr[10000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long sum1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum1 += arr[i];
	}
	sort(arr, arr + n);
	long long total = 0;
	for (int i = 0; i < n ; i++) {
		sum1 -= arr[i];
		total += sum1 - arr[i] * (n - 1 - i);
	}
	cout << 2*total << endl;
}

