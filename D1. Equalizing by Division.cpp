#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int d[200001];
int dp[200001];
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int res = 987654321;
	for (int i = 0; i < v.size(); i++) {
		int cnt = 0;
		int t = v[i];
		while (1) {
			d[t]++; dp[t] += cnt;
			if (d[t] == m) res = min(res, dp[t]);
			if (!t) break;
			t /= 2;
			cnt++;
		}
	}
	cout << res << "\n";
}