#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int n,k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		int temp = 0;
		for (int j = 0; j < k; j++) {
			temp += pow(2, j);
		}
		cout << temp << endl;
	}
}