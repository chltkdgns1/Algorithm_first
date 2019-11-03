#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001],dp[1001];
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	int max = 1, index;
	for (int i = 1; i < n; i++) {
		for (int k = 0; k < i; k++) {
			if (arr[i] > arr[k] && dp[i] < dp[k] + 1) dp[i] = dp[k] + 1;
			if (max < dp[i]) {
				max = dp[i];
				index = i;
			}
		}
	}
	int key;
	for (int k = index; k >= 0; k--) {
		if (k == index) {
			key = dp[k] - 1;
			v.push_back(arr[k]);
		}
		else {
			if (key == dp[k]) {
				key--;
				v.push_back(arr[k]);
				if (key < 0) break;
			}
		}
	}
	cout << max << "\n";
	if (n == 1) cout << arr[0] << "\n";
	else {
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	}
}