#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a = a + b + c + d;
	cout << a / 60 << endl<<a % 60 << endl;
}