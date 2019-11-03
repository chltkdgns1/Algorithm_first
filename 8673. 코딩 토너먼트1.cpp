#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector <int> v;
int res;
int solve(int s, int e) {
	if (s == e) return v[s];
	int m = (s + e) / 2;
	int a = solve(s, m), b = solve(m + 1, e);
	res += abs(a - b);
	return max(a, b);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, cnt = 1; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i <(1<<n); i++) {
			int a; cin >> a;
			v.push_back(a);
		}
		solve(0, (1<<n) - 1);
		cout << "#"<<cnt++<<" "<<res << "\n";
		v.clear();
		res = 0;
	}
}