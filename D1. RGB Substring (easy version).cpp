#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[2001][3], a, b;
string s;

int solve(int idx, int ch,int t) {
	if (idx == a) return 0;

	int &ref = dp[t][ch];
	if (ref) return ref;
	// 0 R 1 G 2 B

	ref = 987654321;

	if (s[idx - 1] == 'R') {
		if (s[idx] == 'G') {
			ref = min(ref, solve(idx + 1, 1, t + 1));
			ref = min(ref,solve(idx + 1))
		}
	}
	else ref = min(ref, solve(idx + 1, 0) + 1);
	ref = min(ref, solve(idx + 1, 1) + 1);
	ref = min(ref, solve(idx + 1, 2) + 1);

	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> a >> b;
		cin >> s;

	}
}