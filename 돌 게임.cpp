#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	while (1) {
		if (n == 3 || n == 1) { cout << "SK"; break; }
		if (n - 3 < 3) n -= 1;
		else n -= 3;
		if (n == 3 || n == 1) { cout << "CY"; break; }
		if (n - 3 < 3) n -= 1;
		else n -= 3;
	}
}