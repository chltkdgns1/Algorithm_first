#include <iostream>
using namespace std;

int a[500001], b[500001];

int main() {
	int aMax = 0, bMax = 0;
	int n, h, Min = 987654321, tmp, cnt = 1;
	cin >> n >> h;
	for (int i = 0; i < n / 2; i++) {
		int inputA, inputB;
		cin >> inputA >> inputB;
		a[inputA]++;
		b[inputB]++;
		if (aMax < inputA) { aMax = inputA; }
		if (bMax < inputB) { bMax = inputB; }
	}
	for (int i = aMax; i >= 1; i--)
		a[i] += a[i + 1];
	for (int i = bMax; i >= 1; i--)
		b[i] += b[i + 1];

	for (int i = 1; i <= h; i++) {
		tmp = a[i] + b[h - i + 1];
		if (tmp < Min)
			cnt = 1, Min = tmp;
		else if (tmp == Min)
			cnt++;
	}
	cout << Min << " " << cnt << '\n';
	return 0;
}
