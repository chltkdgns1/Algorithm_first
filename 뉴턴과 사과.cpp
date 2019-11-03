#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int arr[4]; 
	for (int i = 0; i < 4; i++) cin >> arr[i];
	int a, b, c; cin >> a >> b >> c;
	for (int i = 0; i < 4; i++) {
		if (a == arr[i]) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
}