#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	double x, y, c;
	cin >> x >> y >> c;
	double left = 0, right = min(x,y);
	double mid;
	double ans = 0;
	while (right - left > 1e-6) {
		mid = (left + right) / 2;
		double x1 = sqrt(x*x - mid*mid), y1 = sqrt(y*y - mid*mid);
		double b = mid / (x1 / y1 + 1);
		double a = mid - b;
		double r = (x * a) / mid;
		if (c < r) {
			cout << mid << endl;
			left = mid ;
		}
		else {
			right = mid;
		}
	}
	printf("%.3lf", left);
	system("pause");
}