#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int arr[3];
	string number;
	for (int i = 0; i < 3; i++) cin >> arr[i];
	sort(arr, arr + 3);
	cin >> number;
	for (int i = 0; i < 3; i++) printf("%d ", arr[number[i] - 65]);
}