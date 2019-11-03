#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int a, b, k;
void solve(int index, int t,vector <int> &a) {
	if (t > b) return;
	if (k == index) {
		a.push_back(t);
		return;
	}
	solve(index + 1, t + v[index],a);
	solve(index + 1, t,a);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int c; cin >> c;
		v.push_back(c);
	}
	vector <int> c, d;

	k = a / 2; solve(0, 0, c); 
	k = a; solve(a/2, 0, d);

	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	int res = 0, end = d.size() - 1;
	for (auto x : c) {
		while (end >= 0) {
			if (x + d[end] > b) end--;
			else break;
		}
		res += end + 1;
	}
	cout << res << "\n";
}