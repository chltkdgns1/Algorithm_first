#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> par;
vector <pair<int, int>> v;
int ccw(par a, par b, par c) {
	return a.first*b.second + b.first*c.second + c.first*a.second
		- a.second*b.first - b.second*c.first - c.second*a.first;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 3; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	int d = ccw(v[0], v[1], v[2]);
	if (!d) cout << d;
	else if (d < 0) cout << -1;
	else cout << 1;
}