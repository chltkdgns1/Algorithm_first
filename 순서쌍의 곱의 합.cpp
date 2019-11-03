#include <iostream>
using namespace std;
long long dp[100001];
int arr[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (!i) dp[i] = arr[i];
		else dp[i] = dp[i - 1] + arr[i];
	}
	long long t = 0;
	if (n == 1) {
		cout << arr[0] << "\n";
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		t += (dp[n - 1] - dp[i])*arr[i];
	}
	cout << t << "\n";
}