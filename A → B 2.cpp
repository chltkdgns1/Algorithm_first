#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, max1;
void dfs(long long s,long long cnt) {
	if (s == m) {
		max1 = max(max1, cnt);
		return;
	}
	if (2 * s <= m ) {
		dfs(2 * s, cnt + 1);
	}
	if (10 * s + 1 <= m) {
		dfs(10 * s + 1, cnt + 1);
	}
}
int main() {
	cin >> n >> m;
	dfs(n,0);
	if (!max1) cout << -1 << "\n";
	else cout << max1 + 1 << "\n";
}