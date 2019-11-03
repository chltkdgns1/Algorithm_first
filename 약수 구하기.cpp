#include <iostream>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int c = 0;
	set <int> s;
	for (int i = 1; i*i <= n; i++) {
		if (!(n % i)) {
			s.insert(i), s.insert(n / i);
		}
	}
	for (auto a : s) {
		c++;
		if (c == m) { cout << a << "\n"; return 0; }
	}
	cout << 0 << "\n";
}