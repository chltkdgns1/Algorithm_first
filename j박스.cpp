#include <iostream>
using namespace std;
int main() {
	int t , n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n ; j++) {
			if (j == 0 || j == n - 1) {
				for (int k = 0; k < n; k++) {
					cout << "#";
				}
				cout << endl;
			}
			else {
				cout << "#";
				for (int k = 0; k < n - 2; k++) {
					cout << "J";
				}
				cout << "#";
				cout << endl;
			}
		}
		cout << endl;
	}
}