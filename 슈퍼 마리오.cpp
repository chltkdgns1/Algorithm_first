#include <iostream>
using namespace std;

int main() {
	int arr[10],sum = 0;
	for (int i = 0; i < 10; i++) cin >> arr[i];
	for (int i = 0; i < 10; i++) {
		sum += arr[i];
		if (sum >= 100) {
			// sum - arr[i] 값과  sum 을 비교
			if (100 - (sum - arr[i]) < sum - 100) {
				cout << sum - arr[i] << endl;
			}
			else if (100 - (sum - arr[i]) > sum - 100) {
				cout << sum << endl;
			}
			else if (100 - (sum - arr[i]) == sum - 100) {
				cout << sum << endl;
			}
			return 0;
		}
	}
	cout << sum << endl;
}