#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map <int, int> m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,c = 1; cin >> t;
	while (t--) {
		int n, a; cin >> n;

		vector <pair<int, int>> v;
		vector <int> e;

		for (int i = 0; i < n; i++) cin >> a, m[a]++;
		for (auto a : m) v.push_back({ a.first,a.second });

		cout << "#" << c++ << " ";
		int i = 0;
		if (m.size() == 1) {
			for (int i = 0; i < v[0].second; i++) cout << v[0].first << " ";
		}
		else if (m.size() == 2) {
			if (v[i].first + 1 == v[i + 1].first) {
				for (int z = 1; z >= 0; z--) {
					for (int k = 0; k < v[z].second; k++) cout << v[z].first << " ";
				}
			}
			else {
				for (int z = 0; z <= 1; z++) {
					for (int k = 0; k < v[z].second; k++) cout << v[z].first << " ";
				}
			}
		}
		else {
			while (e.size() != n) {
				if (!v[i].second) {
					i++;
					continue;
				}
				if (i == v.size() - 2) {
					if (e.back() + 1 == v[i].first || v[i].first + 1 == v[i + 1].first) {
						for (int k = 0; k < v[i + 1].second; k++) e.push_back(v[i + 1].first);	
						for (int k = 0; k < v[i].second; k++) e.push_back(v[i].first);
					}
					else {
						for (int k = 0; k < v[i].second; k++) e.push_back(v[i].first);
						for (int k = 0; k < v[i + 1].second; k++) e.push_back(v[i + 1].first);
					}
					break;
				}
				else if (e.empty()) {
					for (int k = 0; k < v[i].second; k++) e.push_back(v[i].first);
					i++;
				}
				else {
					if (e.back() >= v[i].first && v[i].second) {
						for (int k = 0; k < v[i].second; k++) e.push_back(v[i].first);		
						i++;
					}
					else {
						if (e.back() + 1 == v[i].first) {
							e.push_back(v[i + 1].first);
							v[i + 1].second--;
						}
						else {
							for (int k = 0; k < v[i].second; k++) e.push_back(v[i].first);
							i++;
						}
					}
				}
			}

			for (auto a : e) cout << a << " ";
		}
		cout << "\n";
		m.clear();
	}
	return 0;
}