#include <iostream>
using namespace std;

int main() {
	int number,temp=0;
	char array[101] = { NULL };
	char a[1];
	cin >> number;
	cin >> array;
	for (int i = 0; array[i] != NULL; i++) {
		temp++;
		if (temp > number)
			return 0;
	}
	temp = 0;
	for (int i = 0; i<number; i++) {
		a[0] = array[i];
		temp += atoi(a);
	}
	cout << temp << endl;
}