#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int number;
	cin >> number;
	int i = 0;
	while (number) {
		arr[number % 10] ++;
		number /= 10;
	}
	for (int i = 9; i >= 0; i--) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) cout << i;
		}
	}
}