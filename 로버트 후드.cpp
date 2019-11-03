#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;
typedef long long ll;
class pos {
public:
	int x, y, p, q;
	pos(int x,int y) :x(x),y(y),p(1),q(0) {}
};
vector <pos> v;
ll ccw(pos a, pos b, pos c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y;
}
bool cmp(const pos&a, const pos&b) {
	if (1LL * a.q * b.p != 1LL * a.p * b.q) {
		return 1LL * a.q * b.p < 1LL * a.p * b.q;
	}
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back(pos(a, b));
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
			int second = s.back(); s.pop_back();
			int first = s.back();

			if (ccw(v[first], v[second], v[next]) > 0) {
				s.push_back(second);
				break;
			}
		}
		s.push_back(next++);
	}
	int high = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		for (int k = i + 1; k < s.size(); k++) {
			int d = (v[s[i]].x - v[s[k]].x), q = v[s[i]].y - v[s[k]].y;
			high = max(high, d*d + q * q);
		}
	}
	printf("%.6lf", sqrt(high));
}