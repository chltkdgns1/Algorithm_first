#include <iostream>
#include <algorithm>
using namespace std;int arr[3];int main() {for (int i = 0; i < 3; i++) cin >> arr[i];sort(arr, arr + 3);if (arr[1] - arr[0] < arr[2] - arr[1]) cout << arr[1] + arr[1] - arr[0]<< endl;else if (arr[1] - arr[0] > arr[2] - arr[1]) cout << arr[0] + arr[2] - arr[1] << endl;else cout << arr[2] + arr[1] - arr[0] << endl;}