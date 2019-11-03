#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while (n != 1) {
		bool b = 0;
		for (int i = 2; i*i <= n; i++) {
			if (!(n % i)) {
				n /= i;
				cout << i << "\n";
				b = 1;
				break;
			}
		}
		if (!b) {
			cout << n << "\n";
			break;
		}
	}
	system("pause");
}