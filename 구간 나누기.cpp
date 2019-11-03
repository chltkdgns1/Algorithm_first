#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int arr[101];
int dp[101][51];
int solve(int a,int cnt) {
	int &ref = dp[a][cnt];
	if (!cnt) return 0;
	if (a < 0) return  INT_MIN / 2;
	if (ref) return ref;
	ref = solve(a - 1, cnt);
	for (int i = a; i > 0; i--) {
		ref = max(ref, solve(i - 2, cnt - 1) + arr[a] - arr[i - 1]);
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	cout << solve(a,b) << "\n";
}