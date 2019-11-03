#include <iostream>
#include <string>
using namespace std;
string arr;
int str[5];
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int temp;
	cin >> arr;
	str[1] = 1, str[4] = 4;
	for (int i = 0; i < arr.length(); i++) {
		switch (arr[i]) {
		case 'A':
			swap(str[1], str[2]);
			break;
		case 'B':
			swap(str[1], str[3]);
			break;
		case 'C':
			swap(str[1], str[4]);
			break;
		case 'D':
			swap(str[2], str[3]);
			break;
		case 'E':
			swap(str[2], str[4]);
			break;
		case 'F':
			swap(str[3], str[4]);
			break;
		}
	}
	int a, b;
	for (int i = 1; i < 5; i++) {
		if (str[i] == 1) a = i;
		if (str[i] == 4) b = i;
	}
	cout << a << endl;
	cout << b << endl;
}