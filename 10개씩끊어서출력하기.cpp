#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	int n;
	int number1, number2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number1 >> number2;
		cout << number1 + number2 << "\n";
		cin.tie(NULL);
	}
}