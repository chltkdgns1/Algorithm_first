#include <iostream>
using namespace std;
int main() {
	int a; cin >> a; a--;
	if (!((a / 4) % 2)) cout << a % 4 + 1 << "\n";
	else cout << 5 - a % 4 << "\n";
}