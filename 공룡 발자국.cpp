#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

class Data {
public:
	ll x, y, p, q;
};
vector <Data> v;

bool cmp(const Data &a, const Data &b) {
	if (a.q * b.p != a.p * b.q) return a.q*b.p < a.p*b.q;
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

ll pows(ll a) {
	return a * a;
}
ll dis(int a, int b) {
	return pows(v[a].x - v[b].x) + pows(v[a].y - v[b].y);
}

ll ccw(int a, int b, int c) {
	return (v[b].x - v[a].x)*(v[c].y - v[a].y) -
		(v[c].x - v[a].x)*(v[b].y - v[a].x);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b,0,0});
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i < n; i++) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}

	sort(v.begin() + 1, v.end(), cmp);

	vector <int> e;
	e.push_back(0), e.push_back(1);

	bool ch = 0;
	for (int i = 2; i < n; i++) {
		while (e.size() >= 2) {
			int a, b = e.back(); e.pop_back();
			a = e.back();

			if (!ch && ccw(a, b, i) > 0) {
				if (dis(0, b) > dis(0, i)) {
					ch = 1;
					e.push_back(b);
					break;
				}
			}
			else if (ch && ccw(a, b, i) < 0) {
				if (dis(0, b) < dis(0, i)) {
					ch = 0;
					e.push_back(b);
					break;
				}
			}
		}
		e.push_back(i);
	}
	cout << e.size() << "\n";
	for (auto a : e) {
		cout << v[a].x << " " << v[a].y << "\n";
	}
	system("pause");
}