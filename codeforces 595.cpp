#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		vector <int> v;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}

		sort(v.begin(), v.end());

		bool check[101];
		memset(check, 0, sizeof(check));

		int res = 0;
		for (int i = 0; i < n; i++) {
			int t = -1;
			for (int k = 0; k < n; k++) {
				if (!check[k] && t == -1) {
					t = v[k];
					check[k] = 1;
				}
				else if (!check[k] && v[k] - t > 1) {
					t = v[k];
					check[k] = 1;
				}
			}
			res++;
			bool ch = 0;
			for (int i = 0; i < n; i++) {
				if (!check[i]) {
					ch = 1; break;
				}
			}
			if (!ch) break;
		}
		cout << res << "\n";
	}
}