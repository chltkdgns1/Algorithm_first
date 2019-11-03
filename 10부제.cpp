#include <iostream>
using namespace std;
int main() {
	int car;
	int n;
	int col = 0;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> car;
		if (car % 10 == n % 10) {
			col++;
		}
	}
	cout << col << endl;
}