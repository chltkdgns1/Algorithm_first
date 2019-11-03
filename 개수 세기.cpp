#include <iostream>
using namespace std;
int arr[300];
int main() {
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr[a + 100]++;
	}
	cin >> k;
	cout << arr[k + 100] << "\n";
}