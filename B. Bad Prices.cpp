#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		vector <pair<int, int>> v, e;
		int a; cin >> a;
		for (int i = 0; i < a; i++) {
			int c; cin >> c;
			v.push_back({ c,i });
		}

		sort(v.begin(), v.end());

		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			if (e.empty()) e.push_back(v[i]);
			else {
				if (e.back().second < v[i].second) {
					e.pop_back(), e.push_back(v[i]);
				}
				else cnt++;
			}
		}
		cout << cnt << "\n";
	}
}