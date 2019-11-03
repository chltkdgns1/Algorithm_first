#include <iostream>
#include <algorithm>
using namespace std;

int n;
void quicksort(int l, int r, int arr[]) {
	if (l >= r) return;
	int left = l, right = r, pivot = l;
	while (left < right) {
		left++;
		if (arr[pivot] < arr[left]) {
			while (right >= left) {
				if (arr[pivot] > arr[right]) {
					swap(arr[left], arr[right]);
					break;
				}
				right--;
			}
		}
	}
	int t = arr[pivot];
	arr[pivot] = arr[right];
	arr[right] = t;
	pivot = right;
	quicksort(l, pivot - 1, arr);
	quicksort(pivot + 1, r,arr);
}

int main() {
	int arr[1001];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	quicksort(0, n -1, arr);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	system("pause");
}