#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m,dp[50001][3],arr[50001];
int solove(int index, int cnt) {
	if (cnt >= 3 || index + m > n) return 0;
	if (dp[index][cnt]) {
		return dp[index][cnt];
	}
	return dp[index][cnt] = max(arr[index + m] - arr[index] + solove(index + m, cnt + 1), solove(index + 1, cnt));
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	cin >> m;
	cout << solove(0, 0) << "\n";
}