#include <iostream>
using namespace std;

int main() {
	int array[3];
	int temp;
	for (int i = 0; i < 3; i++)cin >> array[i];
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 2; i++) {
			if (array[i] < array[i + 1]) {
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
	cout << array[1] << endl;
}