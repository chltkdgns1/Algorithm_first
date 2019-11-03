#include <iostream>
using namespace std;
char arr[4];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr;
		int n1 = arr[0] - 48;
		int n2 = arr[2] - 48;
		cout << n1 + n2 << endl;
	}
}