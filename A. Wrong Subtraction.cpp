#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < k; i++) {
		if (!(n % 10)) n /= 10;
		else n--;
	}
	cout << n << "\n";
}