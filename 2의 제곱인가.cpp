#include <iostream>
#include <math.h>
using namespace std;

int arr[60];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i <= 30; i++) arr[i] = pow(2, i);
	for (int i = 0; i <= 30; i++) {
		if (arr[i] == n) {
			cout << 1 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
}