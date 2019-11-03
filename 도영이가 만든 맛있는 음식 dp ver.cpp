#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
vector <int> e;
pair <int, int> v[10];
ll n, row = 987654321;
void dfs(int index) {
	if (index == n) {
		ll a = 1, b = 0;
		if (e.empty()) return;
		for (int i = 0; i < e.size(); i++) {
			a *= v[e[i]].first;
			b += v[e[i]].second;
		}
		row = min(row, (abs(a - b)));
		return;
	}
	e.push_back(index);
	dfs(index + 1);
	e.pop_back();
	dfs(index + 1);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	dfs(0);
	cout << row << "\n";
}