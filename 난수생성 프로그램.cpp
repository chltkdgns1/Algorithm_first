#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(time(NULL));
	int n = rand() % 30 + 5, w = rand() % 30 + 1;
	cout << n << "\n"; cout << w << "\n";
	for (int i = 0; i < w; i++) {
		cout << rand() % 30 + 1 << " " << rand() % 30 + 1 << "\n";
	}
	system("pause");
}