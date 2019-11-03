#include <iostream>
using namespace std;


int QuickSort(int first_left, int first_right, int *numbers) { // 치킨 거리 순위
	if (first_left >= first_right) {
		return 0;
	}
	int left = first_left;
	int right = first_right;
	int temp;
	int temp2;
	for (int i = left; i <= right; i++) {
		if (numbers[left] > numbers[i]) {
			if (i - left == 1) {
				temp = numbers[left];
				numbers[left] = numbers[i];
				numbers[i] = temp;
				left = i;
			}
			else {
				temp = numbers[left];
				temp2 = numbers[left + 1];
				numbers[left] = numbers[i];
				numbers[left + 1] = temp;
				numbers[i] = temp2;
				left = left + 1;
			}
		}
	}
	QuickSort(first_left, left - 1, numbers);
	QuickSort(left + 1, first_right, numbers);
}