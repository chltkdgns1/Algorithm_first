#include <iostream>
using namespace std;

int main() {
	int t, n, o_cnt = 0, z_cnt = 0;;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 0) z_cnt++;
		else if (n == 1) o_cnt++;
	}
	if (z_cnt < o_cnt) cout << "Junhee is cute!" << endl;
	else cout << "Junhee is not cute!" << endl;
}