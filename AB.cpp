#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, k, a, b, cnt = 0;
	bool br = 0;
	string t;
	cin >> n >> k;
	for (int i = 1; i <= n ; i++){
		a = i, b = n - i;
		if (a * b >= k) {
			br = 1;break;
		}
	}
	if (!br) { cout << -1 << "\n"; return 0; }
	for (int i = 0; i < n; i++) {
		if (cnt + b > k) {
			t += 'B'; b--;
		}
		else if (cnt + b <= k) {
			t += 'A'; a--;cnt += b;
		}
	}cout << t << "\n";
}