#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double number;
	long long number2 = 1000000000000;
	long long  number3 = sqrt(number2);
	long long number4;
	cout << "number 3   : " << number3 << endl;
	number = number3;
	cout << "number : "<<number << endl;
	double number5 = sqrt(1000000000000);
	cout << "number5 : " << number5 << endl;
	if (number3 - 1 < number5) {
		cout << "¾¾¹ß" << endl;
	}
	system("pause");
}
