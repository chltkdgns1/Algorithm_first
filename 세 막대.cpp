#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int arr[3],d;
	for (int i = 0; i < 3; i++) cin >> arr[i];
	sort(arr, arr + 3);
	d = (arr[0] + arr[1]);
	while (d <= arr[2]) arr[2]--;
	cout << d + arr[2] << "\n";
}