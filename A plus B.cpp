#include <iostream>
using namespace std;

int main() {
	int a, b;
	int n;
	int case_number = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << "Case #" << case_number << ": " << a <<" + "<<b<<" = "<<a+b<< endl;
		case_number++;
	}
}