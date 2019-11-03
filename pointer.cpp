#include <iostream>
using namespace std;

void ChangeNumber(int *number) {
	*number = 3;
}

int main() {
	int number = 10;
	ChangeNumber(&number);
	cout << "number : " << number << endl;
	system("pause");
}

