#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;
class xy {
public:
	ll x, y, index;
};
bool cmp1(const xy&a, const xy&b) {
	if (a.x == b.x) return a.y > b.y;
	else return a.x < b.x;
}
bool cmp2(const xy&a, const xy&b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y > b.y;
}
int sum(vector <int> &tree, int x) {
	int t = 0;
	while (x) {
		t += tree[x];
		x -= (x & -x);
	}
	return t;
}
void update(vector <int> &tree, int i, int diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}
int sizeSum(vector <int> &tree,int a, int b) {
	return sum(tree, b) - sum(tree, a);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <xy> v;
		vector <int> tree(n + 1);
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			xy data;
			data.x = a, data.y = b;
			v.push_back(data);
			update(tree, i + 1, 1);
		}
		sort(v.begin(), v.end(),cmp1);
		for (int i = 0; i < n; i++) v[i].index = i;
		sort(v.begin(), v.end(), cmp2);
		ll total = 0;
		for (int i = 0; i < v.size(); i++) {
			int t = sizeSum(tree, v[i].index + 1 , n);
			total += t;
			update(tree, v[i].index + 1, -1);
		}
		cout << total << "\n";
	}
}