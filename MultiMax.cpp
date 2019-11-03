#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector <ll> v,e;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (!a) {
			cnt = 1;
			continue;
		}
		if (a > 0) v.push_back(a);
		else e.push_back(a);
	}
	sort(v.begin(), v.end());
	vector <ll> res;
	if (v.size() >= 3) {
		int t = v.size() - 1;
		res.push_back(v[t] * v[t - 1] * v[t - 2]);
	}
	else if (v.size() == 2) {
		res.push_back(v[0] * v[1]);
	}
	sort(e.begin(), e.end());
	if (e.size() >= 2) {
		if (v.empty()) res.push_back(e[0] * e[1]);
		else res.push_back(e[0] * e[1] * v.back());
	}
	if (e.size() < 2 && v.size() < 2) {
		if (!e.size() && !v.size()) {
			cout << "0" << "\n";
			return 0;
		}
		else if (!e.size()) {
			if(cnt == 1) 	res.push_back(0);
			else {
				cout << 0 << "\n";
				return 0;
			}
		}
		else if (!v.size()) {
			if (cnt == 1) res.push_back(0);
			else {
				cout << 0 << "\n";
				return 0;
			}
		}
		else {
			if (cnt == 1) res.push_back(0);
			else res.push_back(e.back()*v.back());
		}
	}
	sort(res.begin(), res.end());
	cout << res.back() << "\n";
}

