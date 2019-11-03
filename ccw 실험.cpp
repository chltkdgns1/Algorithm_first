#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

class Data {
public:
	ll x, y, p, q;
};
vector <Data> v;
ll ccw(int a, int b, int c) {
	return (v[b].x - v[a].x)*(v[c].y - v[a].y) -
		(v[c].x - v[a].x)*(v[b].y - v[a].x);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b,0,0 });
	}

	cout << ccw(0, 1, 2) << "\n";
	cout << ccw(0, 1, 3) << "\n";
	system("pause");
}