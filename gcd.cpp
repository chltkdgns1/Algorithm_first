#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		for (int k = 1; k <= a; k++) {
			if (!(a % k)) cout << k << " ";
		}
		cout << "\n";
	}
	system("pause");
}