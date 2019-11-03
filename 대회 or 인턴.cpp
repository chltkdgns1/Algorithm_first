#include <iostream>
using namespace std;
int main() {
	int g, b, in, t , re = 0;
	cin >> g >> b >> in;
	if (b <= g / 2) {
		t = b;
		re += g - 2 * b;
	}
	else {
		t = g / 2;
		re += b - t + g - 2 * t;
	}
	in -= re;
	if (in > 0) {
		t = (3 * t - in) / 3;
	}
	cout << t << endl;
}