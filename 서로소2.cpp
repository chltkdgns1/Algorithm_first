#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <int> e, v, r;
bool check[100001];
int uclid(int a, int b) {
	if (!(a%b)) return b;
	uclid(b, a%b);
}
ll res, c;
ll _union() {
	ll t = 1;
	for (auto a : e) {
		int d = uclid(max(ll(a), t), min(ll(a), t));
		t = t / d * a;
	}
	return c / t;
}
void solve(int v_size, int s, int cnt) {
	if (s == v_size) {
		if (!cnt) return;
		if (!(cnt % 2)) res -= _union();
		else res += _union();
		return;
	}
	e.push_back(v[s]);
	solve(v_size, s + 1, cnt + 1);
	e.pop_back();
	solve(v_size, s + 1, cnt);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 2; i <= 100000; i++) {
		if (!check[i]) {
			r.push_back(i);
			for (int k = 2 * i; k <= 100000; k += i) check[k] = 1;
		}
	}
	while (1) {
		cin >> c;
		if (!c) break;
		int q = c;
		for (int i = 0; i < r.size(); i++) {
			if (!(c % r[i])) {
				v.push_back(r[i]);
				while (!(c % r[i])) c /= r[i];
			}
		}
		if (c != 1) v.push_back(c); 
		c = q;
		solve(v.size(), 0, 0);
		cout << c - res << "\n"; res = 0;
		e.clear(), v.clear();
	}
}