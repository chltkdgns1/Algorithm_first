#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	string number;
	int numbers[10] = { 0 };
	int *set;
	cin >> number;
	set = new int[number.length() + 1];
	for (int i = 0; i < number.length(); i++) {
		set[i] = number[i] - 48;
	}
	for (int i = 0; i < number.length(); i++) {
		if (set[i] == -1) continue;
		for (int j = 0; j < number.length(); j++) {
			if (set[i] == set[j]) {
				numbers[set[i]]++;
				set[j] = -1;
			}
		}
	}
	numbers[6]=ceil(double(numbers[6] + numbers[9])/2);
	numbers[9] = 0;
	int temp = 0;
	for (int i = 0; i < 10; i++) {
		if (temp < numbers[i]) temp = numbers[i];
	}
	cout << temp << endl;
}

//  691123