#include <iostream>
#include <set>
using namespace std;

bool check(int s) {
	set <int> e;
	while (s) {
		if (e.find(s % 10) == e.end()) {
			e.insert(s % 10);
		}
		else return 0;
		s /= 10;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (check(i) == 1) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
}