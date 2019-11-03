#include <iostream>
using namespace std;

int arr[10001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];

	if (n <= m) {
		cout << n << "\n";
		return 0;
	}
	long long left = 0, right = 20000000000, mid, time = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		long long t = 0;
		for (int i = 0; i < m; i++) {
			t += (mid / arr[i] + 1);
		}
		if (t < n) left = mid + 1;
		else {
			time = mid;
			right = mid - 1;
		}
	}
	long long t = 0;
	for (int i = 0; i < m; i++) t += ((time - 1) / arr[i] + 1);
	for (int i = 0; i < m; i++) {
		if ((time) % arr[i] == 0) t++;
		if (t == n) {
			cout << i + 1 << "\n";
			break;
		}
	}
}