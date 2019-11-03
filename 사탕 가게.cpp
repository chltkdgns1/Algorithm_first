#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, p;
double d;
int dp[10001]; // ÀÎµ¦½º´Â µ· °ªÀº Ä®·Î¸®
vector <pair<int, int>> v;
int dfs(int m) {
	int &res = dp[m];
	if (res != -1) return res;
	res = 0;
	for (int i = 0; i < v.size(); i++) {
		if (m - v[i].first >= 0) {
			int t = dfs(m - v[i].first) + v[i].second;
			res = max(res, t);
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		memset(dp, -1, sizeof(dp));
		cin >> n >> d;
		if (n == 0 && d == 0) break;
		for (int i = 0; i < n; i++) {
			int a; double b; // °¡°Ý
			cin >> a >> b;
			v.push_back({ (int)(b * 100 + 0.5),a });
		}
		cout << dfs((int)((d * 100) + 0.5)) << "\n";
		v.clear();
	}
}