#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr1[9];
int arr2[9];
int main() {
	string arr[9] = { "PROBRAIN","GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };
	int data;
	int key = 0;
	int n;
	cin >> n;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data;
			if (key < data) key = data;
		}
		arr1[i] = key;
		arr2[i] = key;
		key = 0;
	}
	sort(arr1, arr1 + 9);
	for (int i = 0; i < 9; i++) {
		if (arr1[8] == arr2[i]) {
			cout << arr[i] << endl;
			break;
		}
	}
}