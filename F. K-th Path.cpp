#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
class Data {
public:
	int x, y; ll z;
	bool operator<(const Data &a) const {
		return z > a.z;
	}
};

vector < map<int, ll>> v(200001);

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, d; cin >> n >> m >> d;
	
	priority_queue <Data> q;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		q.push({ a,b,c });
	}

	ll res = 987654321;
	while (d && !q.empty()) {
		Data w = q.top();
		q.pop();

		int x = w.x, y = w.y;
		ll z = w.z;

		if (v[x].find(y) != v[x].end()) continue;

		for (auto a : v[x]) q.push({ y,a.first,a.second + z});
		for (auto a : v[y]) q.push({ x,a.first,a.second + z });

		v[x][y] = z;
		v[y][x] = z;
		res = z;
		d--;
	}
	cout << res << "\n";
}