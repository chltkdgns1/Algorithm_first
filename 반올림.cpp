#include <iostream>
#include <math.h>
using namespace std;

int ceilFunc(int n) {
	int cnt = 1;
	while (n / (int)pow(10, cnt)) {
		if (5 * (int)pow(10, cnt -1) <= (n % (int)pow(10,cnt))) {
			n += pow(10, cnt);
			n -= n % (int)pow(10, cnt);
		}
		n -= n % (int)pow(10, cnt);
		cnt++;
	}
	return n;
}
int main() {
	int n;
	cin >> n;
	if (n < 10) cout << n << endl;
	else {
		cout << ceilFunc(n) << endl;
	}	
	system("pause");
}