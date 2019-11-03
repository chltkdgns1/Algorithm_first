#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> v;
bool cmp(pair<int, int> &a, pair<int, int > &b) {
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back({ a,i + 1 });
	}

	sort(v.begin(), v.end(),cmp);
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		res += v[i].first * i + 1;
	}
	cout << res << "\n";
	for (auto a : v) cout << a.second << " ";
}