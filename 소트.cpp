#include <iostream>
using namespace std;
int arr[50];
int temp_arr[50];
int checkArr(int n,int a[]) {
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) cnt++;
		else break;
	}
	return cnt;
}
void strCmp(int a[], int b[],int n) {
	for (int i = 0; i < n; i++) b[i] = a[i];
}
int main() {
	int n, k, cnt = 0, temp, br = 0, check,data;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		temp_arr[i] = arr[i];
	}
	cin >> k;
	check = checkArr(n, arr);
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n - i; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				cnt++;
				if ((data = checkArr(n, arr)) > check) {
					check = data;
					strCmp(arr, temp_arr, n);
				}
				if (cnt == k) {
					br = 1; break;
				}
			}
		}
		if (br) { break; br = 0; }
	}
	for (int i = 0; i < n; i++) cout << temp_arr[i] << " ";
	cout << endl;
}