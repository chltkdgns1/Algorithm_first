#include <iostream>
using namespace std;

int main() {
	int n, x, m;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (x > m) {
			cout << m << " ";
		}
	}
	cout << endl;
}