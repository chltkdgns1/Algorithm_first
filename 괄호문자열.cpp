#include <iostream>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	if (n % 2 == 1) {
		cout << n / 2 << " " << n / 2 + 1 << endl;
		system("pause");
		return 0;
	}
	else {
		int i = 2;
		int divide;
		while (1) {
			int temp = 0;
			if (n < i) {
				cout << "-1" << endl;
				system("pause");
				return 0;
			}
			divide = n / i;
			if (divide >= 3 && divide <=100) {
				for (int j = 0; j < divide; j++) {
					temp = temp + i + j;
				}
				if (temp == n) {
					for (int j = 0; j < divide; j++) {
						cout << i + j << " ";
					}
					system("pause");
					return 0;
				}
			}
			i++;
		}
	}
}