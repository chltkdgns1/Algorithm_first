#include <iostream>
using namespace std;

int d[100] = { 0 };

int fibonachi(int x) {
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;
	if (d[x] != 0) return d[x];
	return d[x] = fibonachi(x - 1) + fibonachi(x - 2);
}

int main() {
	cout << fibonachi(100);
	system("pause");
}