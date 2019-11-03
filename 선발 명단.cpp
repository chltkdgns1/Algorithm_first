#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int map[12][12];
int res;
void solve(int index, int t,int cost) {
	if (index == 11) {
		if (t == (1 << 11) - 1) res = max(res, cost);
		return;
	}
	for (int i = 0; i < 11; i++) {
		int d = (1 << (10 - i));
		if (map[index][i] && !(t & d)) {
			solve(index + 1, (t + d),cost + map[index][i]);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 11; i++) {
			for (int k = 0; k < 11; k++) {
				cin >> map[i][k];
			}
		}
		solve(0, 0, 0);
		cout << res << "\n";
		res = 0;
	}
}