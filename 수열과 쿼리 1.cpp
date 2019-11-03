#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector <int> v(100001);
vector <vector<int>> tree(500001);
void init(int node, int s, int e) {
	if (s == e) tree[node].push_back(v[s]);
	else {
		int m = (s + e) / 2;
		int a = node * 2;
		init(a, s, m), init(a + 1, m + 1, e);

		int left = 0, right = 0;
		while (left < tree[a].size() && right < tree[a + 1].size()) {
			if (tree[a][left] <= tree[a + 1][right]) tree[node].push_back(tree[a][left++]);
			else tree[node].push_back(tree[a + 1][right++]);
		}

		while (left < tree[a].size()) {
			tree[node].push_back(tree[a][left++]);
		}
		while (right < tree[a + 1].size()) {
			tree[node].push_back(tree[a + 1][right++]);
		}
	}
}
int qurey(int node, int left, int right, int s, int e,int d) {
	if (right < s || e < left) return 0;
	int m = (s + e) / 2;
	if (left <= s && e <= right) {
		return tree[node].size() - (upper_bound(tree[node].begin(), tree[node].end(), d)
			- tree[node].begin());
	}
	if (s == e) return d < tree[node][0] ? 1 : 0;
	return qurey(node * 2, left, right, s, m, d) +
	qurey(node * 2 + 1, left, right, m + 1, e,d);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int h = log2(n);
	for (int i = 1; i <= n; i++) cin >> v[i];
	init(1, 1, n);

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << qurey(1, a, b, 1, n, c) << "\n";
	}
}