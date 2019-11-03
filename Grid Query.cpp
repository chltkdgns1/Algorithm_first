#include <iostream>
#include <vector>
using namespace std;


void init(vector <int> &tree, int node, int s, int e) {
	if (s == e) tree[node] = 0;
	else {
		int m = (s + e) / 2;
		init(tree, node * 2, s, m), init(tree, node * 2 + 1, m + 1, e);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
	}
}