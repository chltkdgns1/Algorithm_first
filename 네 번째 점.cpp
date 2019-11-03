#include <iostream>
using namespace std;
int c[1001], d[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x = 0, y = 0;
	for (int i = 0; i < 3; i++) {
		int a, b; cin >> a >> b;
		c[a]++, d[b]++;
	}
	for (int i = 1; i <= 1000; i++) {
		if (c[i] == 1) x = i;
		if (d[i] == 1) y = i;
		if (x && y) break;
	}
	cout << x << " " << y << "\n";
}