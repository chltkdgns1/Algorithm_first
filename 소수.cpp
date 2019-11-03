#include <iostream>
using namespace std;
int a[10001];
int main() {
	a[1] = 1;
	for (int i = 2; i*i <= 10000; i++) {
		int k = 2;
		if (!a[i]) {
			while (1) {
				if (i * k > 10000) break;
				a[i*k] = 1;
				k++;
			}
		}
	}
	int c, b, total = 0, min = 1e9;
	cin >> c >> b;
	for (int i = c; i <= b; i++) {
		if (!a[i]) {
			total += i;
			if (min > i) min = i;
		}
	}
	if (!total) cout << -1 << "\n";
	else cout << total << "\n" << min << "\n";
}