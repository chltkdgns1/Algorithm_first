#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v;
vector <int> e;
int dp[101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v.push_back({max(x,y),min(x,y) });
		dp[i] = 1;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) e.push_back(v[i].second);
	
	int res = 1;
	for (int i = 1; i < n; i++) {
		for (int k = 0; k < i; k++) {
			if (e[i] >= e[k] && dp[k] + 1 > dp[i]) {
				dp[i] = dp[k] + 1;
				if (res < dp[i]) res = dp[i];
			}
		}
	}
	cout << res << "\n";
}