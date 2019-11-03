#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();
	long long a, b ;
	cin >> a >> b;
	long long max1 = max(a, b), min1 = min(a, b);
	if (a == b || abs(a - b) == 1) {
		cout << 0 << "\n";
		return 0;
	}
	cout << abs(a - b) - 1 << "\n";
	for (long long i = min1 + 1; i < max1; i++) cout << i << " ";
}