#include <iostream>
using namespace std;

int main() {
	int x, y,z;
	int result;
	cin >> x >> y;
	z = (double)y / x * 100;
	result = (double)(x*(z + 1) - 100 * y) / (99 - z);
	if (99 - z == 0 || result < 0) {
		cout << "-1" << endl;
		return 0;
	}
	else if (result == 0) result++;
    cout << result << endl;
}