#include <iostream>
#include <algorithm>

using namespace std;

int d[150002];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int cnt = 0;
	int len = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (!d[a]) cnt++;
		d[a]++;
		len = max(len, a);
	}

	for (int i = 1; i <= len; i++) {
		if (d[i]) {
			if (d[i] == 1) {
				if (i - 1 >= 1 && !d[i - 1]) d[i - 1] = 1, d[i] = 0;
			}
			else if (d[i] == 2) {
				if (i - 1 >= 1 && !d[i - 1]) d[i - 1] = 1, cnt++;
				else if (!d[i + 1]) d[i + 1] = 1, cnt++;
				else d[i + 1]++;
			}
			else if (d[i] >= 3) {
				if (i - 1 >= 1 && !d[i - 1]) d[i - 1] = 1, cnt++;
				if (!d[i + 1]) d[i + 1] = 1,cnt++;
				else d[i + 1] ++;
			}
		}
	}
	cout << cnt << "\n";
}