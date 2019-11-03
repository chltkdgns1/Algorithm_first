#include <iostream>
#include <algorithm>
using namespace std;int arr[100];int brr[100];int main() {int n;int sum = 0;cin >> n;for (int i = 0; i < n; i++) cin >> arr[i];for (int i = 0; i < n; i++) cin >> brr[i];sort(arr, arr + n);sort(brr, brr + n);int index = n - 1;for (int i = 0; i < n; i++) {sum += arr[index] * brr[i];	index--;}cout << sum << endl;}