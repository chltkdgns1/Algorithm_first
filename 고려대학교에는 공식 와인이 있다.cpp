#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, k, p; cin >> c >> k >> p;
	long long t = 0;
	for (int i = 0; i <= c; i++) {
		t += (k*i + p * i*i);
	}
	cout << t << "\n";
}