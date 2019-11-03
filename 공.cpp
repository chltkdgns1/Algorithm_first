#include <iostream>
using namespace std;

int arr[4] = { 0,1,2,3 };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b ,a1,b1, temp;
		cin >> a >> b;
		for (int j = 1; j <= 3; j++) {
			if (arr[j] == a) a1 = j;
			else if (arr[j] == b) b1 = j;
		}
		temp = arr[a1];
		arr[a1] = arr[b1];
		arr[b1] = temp;
	}
	cout << arr[1] << endl;
}

/*

4
3 1
2 3
3 1
3 2
1 2 3
3 2 1
2 3 1
2 1 3
3 1 2
*/