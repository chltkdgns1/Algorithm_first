#include <iostream>
#define MAX 1000000
using namespace std;

int arr[2000001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, c = 0, d = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 0) {
			a = -a;
			arr[MAX + a]++;
			if (c < MAX + a) c = MAX + a;
		}
		else {
			arr[a]++;
			if (d < a) d = a;
		}
	}

	for (int i = c; i >=MAX + 1; i--) {
		if (arr[i]) {
			for (int k = 0; k < arr[i]; k++) cout << -(i - MAX) << "\n";
		}
	}
	for (int i = 0; i <= d; i++) {
		if (arr[i]) {
			for (int k = 0; k < arr[i]; k++) cout << i << "\n";
		}
	}
}