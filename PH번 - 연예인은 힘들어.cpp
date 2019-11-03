#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e15
using namespace std;

long long dp[101][101];

class Data {
public:
	long long first, second, c;
};
bool cmp(Data &a, Data &b) {
	if (a.first == b.first) {
		if (a.second == b.second) return a.c < b.c;
		return a.second < b.second;
	}
	else return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			dp[i][k] = i == k ? 0 : INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dp[a][b] = c;
		dp[b][a] = c;
	}
	int x, y; cin >> x >> y;
	for (int i = 1; i <= n; i++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				if (dp[a][i] + dp[i][b] < dp[a][b]) {
					dp[a][b] = dp[a][i] + dp[i][b];
				}
			}
		}
	}
	long long res = 1e15;
	vector <Data> v;
	for (int i = 1; i <= n; i++) {
		if (i == x || i == y) continue;
		if (res > dp[x][i] + dp[i][y] && dp[x][i] <= dp[i][y]) {
			res = dp[x][i] + dp[i][y];
			Data d; d.first = res, d.second = dp[x][i], d.c = i;
			if (!v.empty() && v.back().first > res) {
				while (!v.empty()) v.pop_back();
				v.push_back(d);
			}
			else v.push_back(d);
		}
	}
	sort(v.begin(), v.end(), cmp);
	if (v.empty()) cout << -1 << "\n";
	else cout << v[0].c << "\n";
	system("pause");
}