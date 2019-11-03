#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector <pair<int, int>> v;
vector <int> e;
bool visit[100001];

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,a,b; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, int>> res;
		res.push_back({ -1, -1 });
		int max = -987654321;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			visit[a] = 1;
			if (max < a) max = a;
			v.push_back({ a,b });
			e.push_back(a);
		}
		sort(e.begin(), e.end());
		sort(v.begin(), v.end());

		int ss = 0, ee = 0;

		for (int i = 0; i <= max; i++) {
			if(!visit[i]) continue;
			int a = lower_bound(e.begin(), e.end(), i) - e.begin();
			int b = upper_bound(e.begin(), e.end(), i) - e.begin() - 1;
			if (a == b) res.push_back({ v[a].first,v[a].second });
			else if (v[a].second == ee) {
				for (int k = a; k <= b; k++) {
					res.push_back({ v[k].first,v[k].second });
				}
				ss = v[b].first, ee = v[b].second;
			}
			else if (v[b].second == ee) {
				for (int k = b; k >= a; k--) {
					res.push_back({ v[k].first,v[k].second });
				}
				ss = v[a].first, ee = v[a].second;
			}
		}
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a;
			cout << res[a].first << " " << res[a].second << "\n";
		}
		e.clear(), v.clear();
		memset(visit, 0, sizeof(visit));
	}
}