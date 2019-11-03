#include <iostream>
#include <time.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(time(NULL));
	int n = rand() % 20 + 2;
	int m = rand() % 20 + n - 1;
	cout << n << " " << m << " ";
	cout << rand() % n + 1 << " " << rand() % n + 1 << "\n";
	for (int i = 0; i < m; i++) {
		cout << rand() % n + 1 << " " << rand() % n + 1 << " " << rand() % 3 + 1<< "\n";
	}
	system("pause");
}