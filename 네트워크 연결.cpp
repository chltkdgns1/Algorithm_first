#include <iostream>
#include <algorithm>
using namespace std;
class Data {
public:
	int a, b, c;
};
Data d[100001];
int root[1001];
bool cmp(const Data&a, const Data&b) {
	return a.c < b.c;
}

int find(int x) {
	if (root[x] == x) return x;
	return root[x] = find(root[x]);
}

bool _union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	root[y] = x;
	return true;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) root[i] = i;
	for (int i = 0; i < m; i++) cin >> d[i].a >> d[i].b >> d[i].c;
	sort(d, d + m, cmp);
	long long t = 0;
	for (int i = 0; i < m; i++) {
		if (_union(d[i].a, d[i].b)) t += d[i].c;
	}
	cout << t << "\n";
}