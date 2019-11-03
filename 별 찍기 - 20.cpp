#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		if (k % 2) {
			for (int i = 0; i < n; i++) cout << " *";
		}
		else {
			for (int i = 0; i < n; i++) cout << "* ";
		}
		cout << "\n";
	}
}
