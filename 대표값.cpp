#include <iostream>
using namespace std;
int arr[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 0;
	for (int i = 0; i < 10; i++) {
		int a; cin >> a; t += a;
		arr[a]++;
	}
	cout << t / 10 << "\n";
	int max = 0, index = -1;
	for (int i = 0; i <= 1000; i++) {
		if (arr[i] > max) { max = arr[i], index = i; }
	}
	cout << index << "\n";
}