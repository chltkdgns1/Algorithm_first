#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int arr[3], s = 0, cnt = 0, d = 0, c = 0;
	for (int i = 0; i < 3; i++) {
		cin >> arr[i], s += arr[i];
		if (arr[i] == 60) cnt++;
	}
	if (s != 180) cout << "Error" << "\n";
	else if (cnt == 3) cout << "Equilateral" << "\n";
	else {
		if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) cout << "Isosceles" << "\n";
		else cout << "Scalene" << "\n";
	}
}