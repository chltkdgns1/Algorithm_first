#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[(1 << 16)],map[17][17];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) cin >> map[i][k];
	}
	for (int k = 0; k < (1 << n); k++) dp[k] = 987654321;
	string s; int p; cin >> s>> p;
	int bimsk = 0, c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'Y') bimsk += (1 << i),c++;
	}
	dp[bimsk] = 0;
	if (c >= p) {
		cout << 0;
		return 0;
	}
	else if (!c && p) {
		cout << -1;
		return 0;
	}
	int res = 987654321;
	for (int i = bimsk; i < (1 << n); i++) {
		for (int k = 1; k <= n; k++) {
			if(i & (1<<(k - 1))){
				for (int z = 1; z <= n; z++) {
					if (z != k && !(i & (1<<(z - 1)))) {
						int d = (i | (1 << (z - 1)));
						dp[d] = min(dp[d], dp[i] + map[k][z]);
						int cnt = 0;
						for (int q = 0; q < n; q++) {
							if ((1 << q) & d) cnt++;
						}
						if (cnt == p) {
							res = min(res, dp[d]);
						}
					}
				}
			}
		}
	}
	if (res == 987654321) cout << -1 << "\n";
	else cout << res << "\n";
}