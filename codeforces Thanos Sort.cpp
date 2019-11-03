#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
vector <int> v;
int dp[17][17];
int solve(int a, int b) {
	if (a == b) return 1;
	int &ref = dp[a][b];
	if (ref) return ref;
	ref = -INF;
	int ma = -INF;
	for (int i = a; i <= b; i++) {
		if (ma < v[i]) ma = v[i];
		else if (ma > v[i]) {
			int m = (a + b) / 2;
			ref = max(ref,max(solve(a, m), solve(m + 1, b)));
		}
	}
	if (ref == -INF) ref = b - a + 1;
	return ref;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v.push_back(a);
	}
	cout << solve(0, v.size() - 1) << "\n";
}