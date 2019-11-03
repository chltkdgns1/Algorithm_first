#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;
	if (m - 45 < 0) {
		m = 45 - m;
		m = 60 - m;
		if (h == 0) h = 23;
		else h--;
	}
	else {
		m = m - 45;
	}
	cout << h << " " << m << endl;
}