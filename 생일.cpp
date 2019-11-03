#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class name {
public:
	string s;
	int y, m, d;
};
name e[101];

bool cmp(name &a, name &b) {
	if (a.y == b.y) {
		if (a.m == b.m) {
			return a.d < b.d;
		}
		else return a.m < b.m;
	}
	else return a.y < b.y;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> e[i].s >> e[i].d >> e[i].m >> e[i].y;
	}
	sort(e, e + n,cmp);
	cout << e[n - 1].s << "\n" << e[0].s << "\n";
}