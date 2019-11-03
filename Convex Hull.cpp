#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;

class Data {
public:
	ll x, y, p, q;
};
vector <Data> v;

ll ccw(int a, int b, int c) {
	return (v[b].x - v[a].x)*(v[c].y - v[a].y) -
		(v[c].x - v[a].x)*(v[b].y - v[a].y);
}

bool cmp2(const Data &a, const Data & b) {
	if (a.q * b.p != a.p * b.q) {
		return a.q * b.p < a.p * b.q;
	}
	if (a.x == b.x) return a.y > b.y;
	return a.x < b.x;
}

bool cmp(const Data &a, const Data & b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; char c;
		cin >> a >> b >> c;
		if (c == 'Y') v.push_back({ a,b,0,0 });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i < v.size(); i++) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}

	sort(v.begin() + 1, v.end(), cmp2);

	vector <int> s;
	s.push_back(0), s.push_back(1);

	for (int i = 2; i < v.size(); i++) {
		while (s.size() >= 2) {
			int b = s.back(); s.pop_back();
			int a = s.back();

			if (ccw(a, b, i) >= 0) {
				s.push_back(b);
				break;
			}
		}
		s.push_back(i);
	}
	cout << s.size() << "\n";
	for (auto a : s) {
		cout << v[a].x << " " << v[a].y << "\n";
	}
}