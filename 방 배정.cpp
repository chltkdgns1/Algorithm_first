#include <iostream>
using namespace std;

int arr[5];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (y <= 2) arr[0]++;
		else if( y <= 4 ) {
			if (x == 1) arr[1]++;
			else arr[2]++;
		}
		else {
			if (x == 1) arr[3]++;
			else arr[4]++;
		}
	}
	int t = 0;
	for (int i = 0; i < 5; i++) {
		if (!(arr[i] % k)) t += arr[i] / k;
		else t += arr[i] / k + 1;
	}
	cout << t << "\n";
}