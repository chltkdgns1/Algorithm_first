#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	int max = 1;
	for (int i = 1; i < n; i++) {
		for (int k = 0; k < i; k++) {
			if (arr[i] > arr[k] && dp[i] < dp[k] + 1) {
				dp[i] = dp[k] + 1;
			}
			if (dp[i] > max) max = dp[i];
		}
	}
	cout << max << "\n";
}