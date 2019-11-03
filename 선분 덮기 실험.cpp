#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Lower_bound(int v[10], int start, int end, int a) {
	int res = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (v[mid] < a) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return end + 1;
}

int main() {
	int arr[10] = { 10,15,16,17,18,20,25,30,35,40 };
	cout << Lower_bound(arr, 0, 9, 45) << "\n";
	system("pause");
}

// 같거나 작다. 큰 경우는 가장 작을 경우다 .