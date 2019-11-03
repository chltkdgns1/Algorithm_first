#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int res = n;

		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				res = max(res, 2 * max(i + 1, n - i));
			}
		}
		cout << res << "\n";
	}
}