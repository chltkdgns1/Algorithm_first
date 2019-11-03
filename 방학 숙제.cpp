#include <iostream>
using namespace std;

int main() {
	int l, a, b, c, d, cnt = 0;
	int a_t=0, b_t = 0;
	cin >> l >> a >> b >> c >> d;
	while (1) {
		a_t += c;
		b_t += d;
		cnt++;
		if (a_t >= a && b_t >= b) break;
	}
	cout <<l - cnt << endl;
}