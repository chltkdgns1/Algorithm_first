#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <int, pair<int,int>> mp;

class Data {
public:
	int a, b, idx;
};

vector <Data> v;

bool cmp(const Data &a, const Data &b) {
	if (a.b == b.b) return a.idx < b.idx;
	return a.b > b.b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		mp[a].first++;
		if (!mp[a].second) mp[a].second = i;
	}

	for (auto a : mp) {
		v.push_back({ a.first,a.second.first,a.second.second }); // a.first °ª, a.second °¹¼ö
	}

	sort(v.begin(), v.end(),cmp);

	for (auto a : v) {
		for (int i = 0; i < a.b; i++) {
			cout << a.a << " ";
		}
	}
}