#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector <ll> v;
vector <pair<ll, int>> e;

bool cmp(pair<ll, int> &a, pair<ll, int> &b) {
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll size, t; cin >> size >> t;
	ll sum = 0;
	for (int i = 0; i < size; i++) {
		ll a; cin >> a; v.push_back(a);
		sum += a;
		e.push_back({ a,i });
	}

	if (sum <= t) {
		cout << -1 << "\n";
		return 0;
	}

	sort(e.begin(), e.end(),cmp);

	int s = v.size();
	ll st = 0;
	for (int i = 0; i < e.size(); i++) {
		if (t - (s*(e[i].first - st)) > 0) {
			t -= (s*(e[i].first - st));
			st += (e[i].first - st);
			v[e[i].second] = 0;
			s--;
		}
		else {
			int l = 0, r = e[i].first, key = 0;
			while (l <= r) {
				int m = (l + r) / 2;
				if (t < m*s) r = m - 1;
				else l = m + 1, key = m;
			}
			t -= key * s;
			int cnt = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v[i]) {
					if (cnt == t) {
						cout << (i + 1) % v.size() << "\n";
						break;
					}
					cnt++;
				}
			}
			break;
		}
	}
	system("pause");
}