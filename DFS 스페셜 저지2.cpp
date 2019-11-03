#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector <int> v[100001];
bool check1[100001];
bool check2[100001];
vector <int> e, q, d;
void dfs1(int s) {
	if (check1[s]) return;
	check1[s] = 1;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i];
		if (!check1[y]) {
			dfs1(y);
			e.push_back(y);
		}
	}
}
void dfs2(int s) {
	if (check2[s]) return;
	check2[s] = 1;
	for (int i = v[s].size() - 1; i >= 0; i--) {
		int y = v[s][i];
		if (!check2[y]) {
			dfs2(y);
			d.push_back(y);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	dfs1(1);
	dfs2(1);
	e.push_back(1);
	d.push_back(1);
	for (int i = 0; i < n; i++) {
		int r; cin >> r;
		q.push_back(r);
	}
	bool a = false, b = false;
	for (int i = 0; i < n; i++) {
		if (e[n - 1 - i] != q[i]) a = true;
		if (d[n - 1 - i] != q[i]) b = true;
	}
	if (a && b) cout << 0 << "\n";
	else cout << 1 << endl;
}