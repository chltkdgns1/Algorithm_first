#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][51];
bool day[101];
int n, m;
int solve(int idx,int c){
	if (idx > n) return 0;
	int &ref = dp[idx][c];
	if (ref) return ref;
	ref = 987654321;
	if (day[idx]) ref = min(ref, solve(idx + 1, c));
	else {
		ref = min(ref, solve(idx + 1, c) + 10000);
		ref = min(ref, solve(idx + 3, c + 1) + 25000);
		ref = min(ref, solve(idx + 5, c + 2) + 37000);
		if (c >= 3) ref = min(ref, solve(idx + 1, c - 3));
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		day[a] = 1;
	}
	cout << solve(1, 0) << "\n";
}