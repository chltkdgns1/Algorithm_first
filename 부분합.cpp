#include <iostream>
#include <set>
using namespace std;
int arr[100001];
int dp[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] = arr[0];
	int min = 1e9;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + arr[i];
		if (dp[i] >= k) {
			if (min > i + 1) min = i + 1;
			bool br = 0;
			for (int a = i - 1; a >= 0; a--) {
				if (dp[i] - dp[a] >= k) {
					br = 1;
					if (min > i - a) min = i - a;
					break;
				}
			}
		}
	}
	if (min == 1e9) cout << 0 << "\n";
	else cout << min << "\n";
}