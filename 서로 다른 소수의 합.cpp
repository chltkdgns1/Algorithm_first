#include <iostream>
#include <vector>
using namespace std;
int arr[1121];
int dp[1121][15];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	arr[1] = 1;
	for(int i=2;i<=1120;i++){
		int j = 2;
		if (!arr[i]) {
			while (1) {
				if (i*j > 1120) break;
				if (!arr[i*j]) arr[i*j] = 1;
				j++;
			}
		}
	}
	vector <int> v;
	dp[0][0] = 1;
	for (int i = 1; i <= 1120; i++) if (!arr[i]) v.push_back(i);
	for (int i = 0;i<v.size();i++) {
		for (int j = 1120; j >= v[i]; j--) {
			for (int k = 1; k < 15; k++) {
				dp[j][k] += dp[j - v[i]][k - 1];
			}
		}
	}
	int tc, n, k;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		cout << dp[n][k] << endl;
	}
	return 0;
}