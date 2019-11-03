#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector <int> v, e, w;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n ,a; cin >> n;
	
	int mx = 0, mn = 987654321;
	for (int i = 0; i < n; i++) {
		cin >> a; 
		w.push_back(a);
		mx = max(mx, a);
		mn = min(mn, a);
	}

	for (int i = 0; i < w.size();i++) {
		if (w[i] == mx) v.push_back(i);
		if (w[i] == mn) e.push_back(i);
	}

	int res = 987654321;
	for (auto a : v) {
		int t = lower_bound(e.begin(), e.end(), a) - e.begin();
		if (!t) res = min(res, e[t] - a + 1);
		else if (t == e.size()) res = min(res, a - e[t - 1] + 1);
		else {
			res = min(res, e[t] - a + 1);
			res = min(res, a - e[t - 1] + 1);
		}
	}
	cout << res << "\n";
}