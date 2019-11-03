#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (max < a) max = a;
	}
	cout << max << "\n";
}