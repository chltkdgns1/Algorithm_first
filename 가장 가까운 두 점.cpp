#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
typedef pair<int, int> par;
vector <par> v;
map < par, bool> m;

int sqr(int a) {
	return a * a;
}
double dis(par a, par b) {
	return sqr(a.first - b.first) + sqr(a.second - b.second);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	m[{v[0].second, v[0].first}]=1;
	m[{v[1].second, v[1].first}]=1;

	double res = dis(v[0], v[1]);
	int s = 0;
	for (int i = 2; i < n; i++) {
		while (s < i) {
			int d = v[i].first - v[s].first;
			if (d*d <= res) break;
			m.erase({ v[s].second,v[s].first });
			s++;
		}
		int f = sqrt(res);
		auto lo = m.lower_bound({ v[i].second - f,-100000000 });
		auto hi = m.upper_bound({ v[i].second + f,100000000 });

		for (auto a = lo; a != hi; a++) {
			res = min(res, dis({ a->first.second, a->first.first}, v[i]));
		}

		m[{v[i].second, v[i].first}]=1;
	}
	cout << (int)res << "\n";
}