#include <iostream>
#include <time.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(time(0));
	int a = rand() % 30 + 1, b = rand() % 30 + 1;
	cout << a << " " << b << "\n";
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			cout << rand() % 2;
		}
		cout << "\n";
	}
	system("pause");
}