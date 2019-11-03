#include <iostream>
using namespace std;

int main() {
	int n, m, cnt = 1;
	cin >> n >> m;
	if (n == 1 || m == 1) cout << "1" << endl;
	else if (n < 3) {
		if ((m - 1) / 2 > 3) cout << "4" << endl;
		else cout << cnt + (m - 1) / 2 << endl;
	}
	else {
		if (m < 5) cout << m << endl;
		else if (m == 5 || m == 6) cout << "4" << endl;
		else if (m == 7) cout << "5" << endl;
		else {
			cout << m - 2 << endl;
		}
	}
}