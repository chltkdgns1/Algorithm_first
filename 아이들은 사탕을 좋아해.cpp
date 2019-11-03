#include <iostream>
using namespace std;
int main() {
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int number;
		int n, k;
		int temp = 0;
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			cin >> number;
			temp += number / k;
		}
		cout << temp << endl;
	}
}