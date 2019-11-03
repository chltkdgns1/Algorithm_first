#include <iostream>
using namespace std;
int main() {
	char arr[101][101];
	int i = 0;
	while (cin.getline(arr[i],sizeof(arr[i]))) {
		i++;
	}
	for (int j = 0; j < i; j++) {
		cout << arr[j] << endl;
	}
}