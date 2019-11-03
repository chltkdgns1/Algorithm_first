#include <iostream>
using namespace std;

int main() {
	int number1=1, number2=1; // number1 은 분자 number2 분모
	int test_number;
	int case_ = 2;
	int cnt = 1;
	cin >> test_number;
	if (test_number == 1) {
		cout << number1 << "/" << number2 << endl;
		return 0;
	}
	while (1) {	    
		if (case_ % 2 == 0) {
			number2++;
			cnt++;
			if (cnt == test_number) {
				cout << number1 << "/" << number2 << endl;
				return 0;
			}
			for (int i = 0; i < case_ - 1; i++) {
				number2--;
				number1++;
				cnt++;
				if (cnt == test_number) {
					cout << number1 << "/" << number2 << endl;
					return 0;
				}
			}
		}
		else {
			number1++;
			cnt++;
			if (cnt == test_number) {
				cout << number1 << "/" << number2 << endl;
				return 0;
			}
			for (int i = 0; i < case_ - 1; i++) {
				number2++;
				number1--;
				cnt++;
				if (cnt == test_number) {
					cout << number1 << "/" << number2 << endl;
					return 0;
				}
			}
		}		
		case_++;
	}
}