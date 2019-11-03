#include <iostream>
#define MAX 2000000
using namespace std;
typedef long long ll;
int v[41];
int m[2 * MAX + 1];
ll n, r, res;
void solve(int s, int sum) {
	if (n / 2 == s) {
		m[sum + MAX]++;
		return;
	}
	solve(s + 1, sum + v[s]);
	solve(s + 1, sum);
}
void solve2(int s, int sum) {
	if (n == s) {
		if (r - sum + MAX < 0 || r - sum + MAX > 2 * MAX) return;
		res += m[r - sum + MAX];
		return;
	}
	solve2(s + 1, sum + v[s]);
	solve2(s + 1, sum);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> r;
	for (int i = 0; i < n; i++) cin >> v[i];
	solve(0, 0);
	solve2(n / 2, 0);
	if (!r) res--;
	cout << res << "\n";
}