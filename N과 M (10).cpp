#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, m, d[10], arr[10001];
vector <int> v;
set <int> s;
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < idx; i++) {
			cout << d[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (arr[v[i]] >= 1) {
			if (!d[idx]) {
				d[idx] = v[i];
				arr[v[i]]--;
				dfs(idx + 1, cnt + 1);
				arr[v[i]]++;
			}
			else {
				if (d[idx - 1] <= v[i]) {
					d[idx] = v[i];
					arr[v[i]]--;
					dfs(idx + 1, cnt + 1);
					arr[v[i]]++;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr[a]++;
		s.insert(a);
	}
	for (auto a : s) v.push_back(a);
	dfs(0, 0);
}