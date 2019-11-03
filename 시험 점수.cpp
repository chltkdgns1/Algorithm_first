#include <iostream>
using namespace std;
int arr[5];
int brr[5];
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
		arr[4] += arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> brr[i];
		brr[4] += brr[i];
	}
	if (arr[4] > brr[4]) cout << arr[4] << endl;
	else cout << brr[4] << endl;

}