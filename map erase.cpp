#include <iostream>
#include <map>
using namespace std;

int main() {
	map <int, int> m;
	m[0] = 1;
	m[1] = 2;
	m[2] = 3;
	m[5] = 4;

	auto a = m.erase(3);
	cout << a << "\n";
	system("pause");
}