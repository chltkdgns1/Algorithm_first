#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
typedef pair <int, int> par;
vector <par> v, e;
bool cmp(const par &a, const par &b) {
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b,x,y; cin >> a >> b;
	long long r = 0; // 맨 처음 위치에서의 거리 총합
	x = y = 0;
	for (int i = 0; i < a; i++) {
		int c, d; cin >> c >> d;
		r += abs(c - x) + abs(d - y);
		v.push_back({ c,d });
		e.push_back({ d,c });
	}
	sort(v.begin(), v.end()), sort(e.begin(), e.end());
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'S') {
			int d = upper_bound(e.begin(), e.end(), par(y,0), cmp) - e.begin();
			r += 2 * d - e.size();
			y++;
		}
		else if (s[i] == 'J') {
			int d = lower_bound(e.begin(), e.end(), par(y,0), cmp) - e.begin();
			r += -d + (e.size() - d);
			y--;
		}
		else if (s[i] == 'I') {
			int d = upper_bound(v.begin(), v.end(), par(x,0),cmp) - v.begin();
			r += 2 * d - v.size();
			x++;
		}
		else {
			int d = lower_bound(v.begin(), v.end(), par(x,0),cmp) - v.begin();
			r += -d + (v.size() - d);
			x--;
		}
		cout << r << "\n";
	}
}