#include <iostream>
#include <set>
using namespace std;
set <int> x;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, t = 0, d = 0;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int c; cin >> c;
		x.insert(c);
	}
	for (int i = 0; i < b; i++) {
		int c; cin >> c;
		if (x.find(c) == x.end()) t++;
		else d++;
	}
	cout << t + a - d << "\n";
}