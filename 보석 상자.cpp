#include <iostream>
using namespace std;
int arr[300001];
int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int max = 0;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}
	int left = 1, right = max, mid;
	int ans = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += arr[i] / mid ;
			if (arr[i] % mid != 0) cnt++;
		}
		if (n < cnt) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans << endl;
}