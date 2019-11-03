#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector <pair<int, int>> v;
bool check[101];
bool dfs(int x, int y, int e_x, int e_y, int have) {
	if ((abs(x - e_x) + abs(y - e_y)) <= 1000) {
		return true; // happy
	}
	for (int i = 0; i < v.size(); i++) {
		if (check[i] == false) {
			if ((abs(x - v[i].first) + abs(y - v[i].second)) <= 1000) {
				check[i] = true;
				if (dfs(v[i].first, v[i].second, e_x, e_y, 20) == true) return true;
			}
		}
	}
	return false;
}
int main() {
	int t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x1, y1, x2, y2;
		cin >> x1 >> y1;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		cin >> x2 >> y2;
		if (dfs(x1, y1, x2, y2, 20) == true) cout << "happy" << "\n";
		else cout << "sad" << "\n";
		for (int i = 0; i <= n; i++) check[i] = 0;
		v.clear();
	}
}