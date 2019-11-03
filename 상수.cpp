#include <iostream>
using namespace std;
void Temp(char *array);
int main() {
	char number1[4], number2[4];
	int number_1, number_2;
	cin >> number1 >> number2;
	Temp(number1);
	Temp(number2);
	number_1 = atoi(number1);
	number_2 = atoi(number2);
	if (number_1 > number_2) cout << number_1<<endl;
	else cout << number_2<<endl;
}

void Temp(char *array) {
	char temp = array[0];
	array[0] = array[2];
	array[2] = temp;
}