#include <iostream>
using namespace std;

int main() {
	int n;
	int cnt = 1;
	cin >> n;
	while (1) {
		if (n == 1) {
			cout << cnt << endl;
			return 0;
		}
		if (n % 2 == 0) {
			n = n / 2;
		}
		else {
			n = 3 * n + 1;
		}
		cnt++;
	}
}