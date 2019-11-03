#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int dp[10001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector <int> v;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}
		int m; cin >> m;
		dp[0] = 1;
		for (int i = 0; i < v.size(); i++) {
			for (int k = v[i]; k <= m; k++) {
				dp[k] += dp[k - v[i]];
			}
			for (int i = 1; i <= m; i++) {
				cout << dp[i] << " ";
			}
			cout << "\n";
		}
		cout << dp[m] << "\n";
		memset(dp, 0, sizeof(dp));
	}
	system("pause");
}