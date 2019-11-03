#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector <int> v[100001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	map <vector<int>, int> mp;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!v[i].size()) {
			cout << -1 << "\n";
			return 0;
		}
		sort(v[i].begin(), v[i].end());
		if (!mp[v[i]]) mp[v[i]] = ++cnt;
		if (cnt > 3) {
			cout << -1 << "\n";
			return 0;
		}
	}
	if (cnt != 3) {
		cout << -1 << "\n";
		return 0;
	}
	for(int i=1;i<=n;i++) cout << mp[v[i]] << " ";
}