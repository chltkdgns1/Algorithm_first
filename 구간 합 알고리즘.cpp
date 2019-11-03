#include <iostream>
using namespace std;

int main() {
	int arr[11] = { 0,1,2,3,4,5,6,7,8,9,10 }, d[11];
	for (int i = 0; i < 11; i++) {
		if (!i) d[i] = arr[i];
		else {
			d[i] = d[i - 1] + arr[i];
		}
	}
	int n; // Äõ¸®ÀÇ ¼ö
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << d[b] - d[a - 1] << endl;
	}
}