#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001], dp1[1001], dp2[1001], brr[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		dp1[i] = dp2[i] = 1;
		cin >> arr[i];
		brr[n - 1 - i] = arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++) {
			if (arr[i] > arr[k] && dp1[i] < dp1[k] + 1) {
				dp1[i] = dp1[k] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++) {
			if (brr[i] > brr[k] && dp2[i] < dp2[k] + 1) {
				dp2[i] = dp2[k] + 1;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, dp1[i] + dp2[n - 1 - i]);
	}
	cout << res - 1<< "\n";
}