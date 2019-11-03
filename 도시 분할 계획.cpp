#include <iostream>
#include <algorithm>
using namespace std;
class Data {
public:
	int a, b, d;
};
Data dat[1000001];
int root[100001];
bool cmp(const Data&a, const Data&b) {
	return a.d < b.d;
}
int find(int x) {
	if (root[x] == x)
		return x;
	else
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
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) root[i] = i;
	for (int i = 0; i < k; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		dat[i].a = a,dat[i].b = b, dat[i].d = d;
	}
	sort(dat, dat + k, cmp);
	long long t = 0;
	int max = 0;
	for (int i = 0; i < k; i++) {
		if (_union(dat[i].a, dat[i].b)) {
			if (max < dat[i].d) max = dat[i].d;
			t += dat[i].d;
		}
	}
	cout << t - max<< "\n";
}