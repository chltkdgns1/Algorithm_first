#include <iostream>
#include <algorithm>
using namespace std;

int map[1025][1025];

int solve(int a, int b,int c,int d) {
	if (a == c && b == d) return map[a][b];

	int x = (a + c) / 2, y = (b + d) / 2;
	int arr[4];
	arr[0] = solve(a, b, x, y);
	arr[1] = solve(x + 1, b, c, y);
	arr[2] = solve(a, y + 1, x, d);
	arr[3] = solve(x + 1, y + 1, c, d);

	sort(arr, arr + 4);
	return arr[2];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) cin>>map[i][k];
	}

	cout << solve(1, 1, n, n) << "\n";
}