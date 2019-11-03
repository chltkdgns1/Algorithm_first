#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
class info {
public:
	int x, y, p, q;
};
vector <info> v;
bool cmp(const info &a, const info &b) {
	if (1LL * a.q * b.p != 1LL * b.q * a.p) {
		return 1LL * a.q * b.p < 1LL * b.q * a.p;
	}
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}
ll ccw(info a, info b, info c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x *a.y - c.x*b.y - a.x*c.y;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 1; i < n; i++) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}
	sort(v.begin() + 1, v.end(), cmp);

	vector <int> s;
	s.push_back(0), s.push_back(1);
	int next = 2;
	while (next < n) {
		while (s.size() >= 2) {
			int first, second;
			second = s.back(); s.pop_back();
			first = s.back();

			if (ccw(v[first], v[second], v[next]) > 0) {
				s.push_back(second);
				break;
			}
		}
		s.push_back(next++);
	}
	cout << s.size() << "\n";
}