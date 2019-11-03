#include <iostream>
#include <set>
using namespace std;
multiset <int> s;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m ; i++) {
		int a; cin >> a;
		s.insert(a);
	}
	for (auto a : s) cout << a << " ";
}