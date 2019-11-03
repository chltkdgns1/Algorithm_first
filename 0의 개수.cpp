#include <iostream>
using namespace std;
int check(int n) {
	if (!n) return 1;
	int cnt = 0;
	while (n) {
		if(!(n %10)) cnt++;
		n /= 10;
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int t = 0;
		for (int i = a; i <= b; i++) t += check(i);
		cout << t << "\n";
	}
}