#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		cout << (2 * m - n)  << " " << m - (2 * m - n)  << endl;
	}
	system("pause");
}