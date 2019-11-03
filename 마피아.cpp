#include <iostream>
using namespace std;

int arr[500000];
int check[500001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, number, data = 0, cnt = 1, total = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		if (check[i] == 0) check[i] = 1;
		else continue;
		while (1) {
			if (arr[i] < i) break;
			if (check[i] == 1) check[arr[i]] = -1;
			else check[arr[i]] = 1;
			i = arr[i];
		}
	}
}