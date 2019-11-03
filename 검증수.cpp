#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 0;
	for (int i = 0; i < 5; i++) {
		int a; cin >> a;
		t += a * a;
	}
	cout << t % 10 << "\n";
}