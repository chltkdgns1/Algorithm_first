#include <iostream>
using namespace std;
int main() {
	int x_a, y_b, y_c, y_d,p,x_t=0,y_t=0;
	cin >> x_a >> y_b >> y_c >> y_d >> p;
	x_t = x_a * p;
	if (p > y_c) y_t = y_b + (p - y_c) * y_d;
	else y_t = y_b;
	if (x_t < y_t) cout << x_t << endl;
	else cout << y_t << endl;
}