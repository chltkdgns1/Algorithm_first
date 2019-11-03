#include <iostream>
using namespace std;
void Check(int number);
int array_[100001];
int main() {
	for (int i = 0; i < 10000; i++) array_[i] = i + 1;
	for (int i = 0; i < 10000; i++)
		Check(i);
	for (int i = 0; i < 10000; i++) {
		if (array_[i] != -1) {
			printf("%d\n", array_[i]);
		}
	}
}

void Check(int number) {
	if (number > 10000) {
		return;
	}
	int temp = number;
	int temp_data = 0;
	while (number / 10 != 0) {
		temp_data += number % 10;
		number = number / 10;
	}
	temp_data = temp_data + number + temp;
	array_[temp_data - 1] = -1;
}