#include <iostream>
using namespace std;

void a(int b[][3]) {

}

int main() {
	int arr[3] = { 1,2,3 };
	a(arr);
	cout << arr[0] << endl;
	system("pause");
}