#include <iostream>
using namespace std;

int main() {
	for (int i = 1000; i <= 9999;i++) {
		int sum1 = 0, sum2 = 0, sum3 = 0;
		int n = i;
		while (n) {
			sum1 += n % 10;
			n = n / 10;
		}
		n = i;
		while (n) {
			sum2 += n % 12;
			n = n / 12;
		}
		n = i;
		while (n) {
			sum3 += n % 16;
			n = n / 16;
		}
		if (sum1 == sum2 && sum2 == sum3) {
			cout << i << endl;
		}
	}
}