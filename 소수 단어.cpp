#include <iostream>
using namespace std;

char arr[21];
int main() {
	cin >> arr;
	int temp = 0;
	for (int i = 0; arr[i] != NULL; i++) {
		if (97 <= arr[i] && arr[i] <= 122) temp += arr[i] - 96;
		else if (65 <= arr[i] && arr[i] <= 90) temp += arr[i] - 38;
	}
	if (temp == 1 ) cout << "It is a prime word." << endl;
	else {
		for (int i = 2; i < temp; i++) {
			if (temp % i == 0) {
				cout << "It is not a prime word." << endl;
				return 0;
			}
		}
		cout << "It is a prime word." << endl;
	}
}