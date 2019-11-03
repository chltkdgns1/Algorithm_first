#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long n, l,w,h;
	double data;
	cin >> n >> l >> w >> h;
	int cnt = 100;
	double left = 0, right = max(l, max(w, h));
	while (cnt--) {
		double middle = (left + right) / 2;
		if (middle <= l && middle <= w && middle <= h) {
			if (n <= (long long)(l / middle) * (long long)(w / middle) * (long long)(h / middle)) left = middle;
			else right = middle;
		}
		else right = middle;
	}
	printf("%.10lf", left);
}