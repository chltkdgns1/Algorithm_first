#include <iostream>
#include <algorithm>
using namespace std;
int arr[3];
int main() {
	int n;
	int number = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];
		}
		sort(arr, arr + 3);
		if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
			cout << "Scenario #" << number << ":" << endl;
			cout << "yes" << endl<<endl;
		}
		else {
			cout << "Scenario #" << number << ":" << endl;
			cout << "no" << endl<<endl;
		}
		number++;
	}

}