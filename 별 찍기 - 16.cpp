#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "*";
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		if (i == 0) {
			for (int j = 0; j < n - 1; j++) cout << " ";
			cout << "*" << endl;
			continue;
		}
		if (n != 2) {
			for (int j = 0; j < n - 1 - i; j++) cout << " ";
			cout << "*";
			for (int j = 0; j < 2 * i - 1; j++) cout << " ";
			cout << "*";
			cout << endl;
		}
	}
	for (int j = 0; j < 2 * n - 1; j++) cout << "*";
	cout << endl;
}