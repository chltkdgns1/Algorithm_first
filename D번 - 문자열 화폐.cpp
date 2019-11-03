#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	if (n * 26 < m || n > m) {
		cout << "!" << "\n";
		return 0;
	}

	string res;
	int t = n;
	for (int i = 0; i < n; i++) res += 'A';

	for (int i = n - 1; i >= 0; i--) {
		if (t + 25 <= m) res[i] = 'Z', t += 25;
		else {
			res[i] += m - t;
			break;
		}
	}
	cout << res << "\n";
}