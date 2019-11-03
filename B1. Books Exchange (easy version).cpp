#include <iostream>
#include <vector>
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

		for (auto a : v) {
			int idx = -1, cnt = 0;
			while (a != idx + 1) {
				if (idx == -1) idx = a - 1;
				idx = v[idx] - 1;
				cnt++;
			}
			cout << cnt << " ";
		}
		cout << "\n";
	}
}