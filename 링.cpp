#include <iostream>
using namespace std;
int uclid(int a, int b) {
	if (!(a % b)) return b;
	uclid(b,a%b);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a; cin >> n;
	for (int i = 0; i < n; i++) {
		int b; cin >> b;
		if (!i) a = b;
		else {
			int d = uclid(a, b);
			cout << a / d << "/" << b / d << "\n";
		}
	}
}