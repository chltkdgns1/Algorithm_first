#include <iostream>
using namespace std;
int arr[51];
int main() {
	int n, t,sum = 0;
	cin >> n>>t;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int i = 1;
	for(; i <= n; i++) {
		sum += arr[i];
		if (sum > t) {
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << i - 1 << endl;
}