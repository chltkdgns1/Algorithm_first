#include <iostream>
using namespace std;

int arr[200001],brr[200001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a; cin >> n >> m >> a;

	int w = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i >= a) brr[w++] = arr[i];
	}
	
	int d, t = n - a + 1;
	while (m--) {
		cin >> d;
		if (d <= a - 1) cout << arr[d + 1] << "\n";
		else {
			d -= a - 1;
			cout << brr[d % t] << "\n";
		}
	}
}