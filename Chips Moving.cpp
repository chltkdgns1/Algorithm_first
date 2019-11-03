#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		if (!(c % 2)) a++;
		else b++;
	}
	cout << min(a, b) << "\n";
}