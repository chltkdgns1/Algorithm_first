#include <iostream>
using namespace std;
int main() {
	int arr[10001], left = 0, right = 0, now = 0, cnt = 0, n, m;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (1) {
		if (now >= m) now -= arr[left++];
		else if (right == n) break;
		else now += arr[right++];
		if (now == m) cnt++;
		
	}
	cout << cnt << "\n";
}