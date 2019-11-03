#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	while (cin >> n) {
		int cnt = 1,num = 1;
		while (num % n) {
			num = num * 10 + 1;
			num %= num %n;
			cnt++;
		}
		cout << cnt << endl;
	}
}