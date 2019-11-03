#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0; return 0;
	}
	int k = -2;
	string t;
	while (n != 0) {
		if (n % k == 0 || n > 0) {
			t += n % k + 48;
			n /= k;
		}
		else {
			t += n - (n / k + 1) * k + 48;
			n = n / k + 1;
		}
	}
	reverse(t.begin(), t.end());
	cout << t << "\n";
}