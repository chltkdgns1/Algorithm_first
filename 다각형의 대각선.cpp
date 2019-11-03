#include <iostream>
using namespace std;
int main() {
	int number;
	cin >> number;
	int temp = 1;
	for (int i = number; i >= number - 3; i--) temp *= i;
	cout << temp / 24 << endl;
}