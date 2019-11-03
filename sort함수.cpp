#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	sort(arr, arr + 5);
	for (int i = 0; i < 10; i++) cout << arr[i] << " ";
	cout << endl;
	system("pause");
}