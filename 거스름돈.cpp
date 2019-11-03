#include <iostream>
using namespace std;

int main() {
	int arr[6] = { 500,100,50,10,5,1 };
	int p;
	int col = 0;
	cin >> p;
	p = (1000 - p);
	for (int i = 0; i < 6; i++) {
		if (p / arr[i] > 0) {
			col += p / arr[i];
			p = p % arr[i];
		}
	}
	cout << col << endl;
}