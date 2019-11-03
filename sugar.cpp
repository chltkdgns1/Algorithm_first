#include <iostream>
using namespace std;


bool SugarNumber(int number, int *ans);
int main() {
	int number;
	int ans;
	cin >> number;
	if (number >= 3 && number <= 5000) {
		if (SugarNumber(number, &ans) == true) {
			cout << ans << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}
	else {
		cout << "-1" << endl;
	}
}

bool SugarNumber(int number, int *ans) {
	int remainder;
	int five;
	int three;
	for (int i = 0; number - 3 * i >= 0; i++) {
		remainder = number - 3 * i;
		if (remainder % 5 == 0) {
			five = remainder / 5;
			three = i;
			*ans = five + three;
			return true;
		}
		else if (number - 3 * (i + 1) < 0) {
			if (number % 3 == 0) {
				*ans = i;
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

