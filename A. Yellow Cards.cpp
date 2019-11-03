#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a1, a2, k1, k2, n; cin >> a1 >> a2 >> k1 >> k2 >> n;
	int res1 =0, res2 = 0;

	int t = a1 * (k1 - 1) + a2 * (k2 - 1);
	if (t >= n) res1 = 0;

	else res1 = n - t;
	if (k1 < k2) {
		swap(k1, k2);
		swap(a1, a2);
	}
	if (k2*a2 == n) res2 = a2;
	else if (k2*a2 < n) {
		res2 += a2;
		n -= k2 * a2;
		res2 += n / k1;
	}
	else res2 += n / k2;
	cout << res1 << " " << res2 << "\n";
}