#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) dp[i] = 987654321;
	dp[n] = 0;
	for (int i = n; i > 1; i--) {
		if (!(i % 3)) dp[i / 3] = min(dp[i / 3], dp[i] + 1);
		if (!(i % 2)) dp[i / 2] = min(dp[i / 2], dp[i] + 1);
		dp[i - 1] = min(dp[i - 1], dp[i] + 1);
	}
	int index = 1;
	vector <int> v;
	while (index != n) {
		v.push_back(index);
		if (index*3 <= n && dp[index * 3] == dp[index] - 1) index *= 3;
		else if (index * 2 <= n && dp[index * 2] == dp[index] - 1) index *= 2;
		else if(index + 1 <= n) index += 1;
	}
	v.push_back(n);
	cout << dp[1] << "\n";
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
}