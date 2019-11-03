#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int c = 0, d = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (!(a % 2)) c++;
		else d++;
	}
	cout << min(c, d) << "\n";
}