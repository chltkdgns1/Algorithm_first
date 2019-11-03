#include <iostream>
using namespace std;

int main() {
	int number;
	int cnt = 0;
	cin >> number;
	while (1) {
		if (number == 1) {
			cout << cnt << endl;
			system("pause");
			return 0;
		}
		if (number % 3 == 0) {
			number = number / 3;
			cnt++;
		}
		else {
			number--;
			cnt++;
		}
	}
}