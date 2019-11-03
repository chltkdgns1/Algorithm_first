#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

typedef long long ll;
pair<ll, int> map[1001][1001];
int dp[1001][1001];
ll gcd(int a, int b) {
	if (!(a%b)) return b;
	return gcd(b, b%a);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (i == k) continue;
			map[i][k].first = 1e13;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		map[a][b].first = c;
		map[a][b].second = a;
		dp[a][b] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			for (int z = 0; z < n; z++) {
				if (map[k][z].first > map[k][i].first + map[i][z].first) {
					map[k][z].first = map[k][i].first + map[i][z].first;
					map[k][z].second = map[i][z].second;
					dp[k][z] = dp[k][i] + 1;
				}
			}
		}
	}

	double res = 1e13;
	int rx = -1, ry = -1;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (map[i][k].first == 1e13 || !map[i][k].first ||
				map[k][i].first == 1e13) continue;

			int d = map[i][k].first + map[k][i].first;
			int cnt = 2, next = k;

			cout << cnt << " " << dp[i][k] << "\n";
			while (i != map[i][next].second) {
				next = map[i][next].second;
				cnt++;
			}
			double r = double(d) / cnt;

			if (res > r) {
				res = r, rx = d, ry = cnt;
			}
		}
	}
	if (rx == -1 && ry == -1) {
		cout << 0 << " " << 0 << "\n";
		return 0;
	}
	ll d = gcd(rx, ry);
	cout << rx / d << " " << ry / d << "\n";
	system("pause");
}