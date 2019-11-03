#include <iostream>
using namespace std;

int main() {
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < i ; j++) {
			cout << " ";
		}
		for (int j = number - i; j > 0; j--) {
			cout << "*";
		}
		cout << endl;
	}
}