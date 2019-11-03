#include <iostream>
using namespace std;

int main() {
	int n, br = 0;
	cin >> n;
	for (int i = n; i > 0; i--) {
		int s = i;
		while (s) {
			if (s % 10 - 4 != 0 && s % 10 - 7 != 0) {
				br = 1; break;
			}
			s /= 10;
		}
		if (br) { br = 0; continue; }
		cout << i << endl;
		break;
	}
}