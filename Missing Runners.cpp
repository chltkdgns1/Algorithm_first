#include <iostream>
using namespace std;

int arr[50000];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a; cin >> a; arr[a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!arr[i]) {
			cout << i << "\n";
			break;
		}
	}
}