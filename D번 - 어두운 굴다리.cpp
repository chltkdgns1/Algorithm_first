#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	int left = 0, right = 100000, mid;
	int res = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		vector <pair<int, int>> r;
		for (int i = 0; i < v.size(); i++) {
			int s = v[i] - mid;
			int e = v[i] + mid;
			r.push_back({ s,e });
		}
		bool c = 0;
		int temp = 0;
		for (int i = 0; i < r.size(); i++) {
			int s = r[i].first;
			int e = r[i].second;
			if (!i) {
				if (s > 0) { c = 1; break; }
				else temp = e;
			}
			else {
				if (temp < s) { c = 1; break; }
				else temp = e;
			}
			if (i == r.size() - 1) {
				if (temp < n) c = 1;
			}
		}
		
		if (!c) {
			right = mid - 1;
			res = mid;
		}
		else left = mid + 1;
	}
	cout << res << "\n";
}