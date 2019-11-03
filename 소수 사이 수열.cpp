#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool ch[1299710];
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	for (int i = 2; i <= 1299709; i++) {
		if (!ch[i]) {
			v.push_back(i);
			for (int k = i * 2; k <= 1299709; k += i) ch[k] = 1;
		}
	}
	while (t--) {
		int n; cin >> n;
		int d = lower_bound(v.begin(), v.end(), n) - v.begin();
		if (v[d] == n) cout << 0 << "\n";
		else cout << v[d] - v[d - 1] << "\n";
	}
}

/*
#include <stdio.h>
bool isP(int x) {
	for (int i = 2; i *i <= x; i++) {
		if (!(x%i)) return false;
	}
	return true;
}
int main(void) {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int x; scanf("%d", &x);
		int l = x, r = x;
		while (!isP(l))l--;
		while (!isP(r))r++;
		printf("%d\n", r - l);
	}
}

*/