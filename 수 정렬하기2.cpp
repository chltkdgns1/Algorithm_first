#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) scanf_s("%d",&arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
	system("pause");
}