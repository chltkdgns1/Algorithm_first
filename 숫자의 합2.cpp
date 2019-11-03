#include <iostream>
using namespace std;

int main() {
	int n;
	int temp = 0;
	char array[100];
	cin >> n;
	cin >> array;
	for (int i = 0; i < n; i++) {
		temp += (array[i] - 48);
	}
	cout << temp << endl;
	system("pause");
}