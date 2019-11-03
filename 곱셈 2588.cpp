#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	int n, ten = 1, sum = 0;
	cin >> n >> s;
	for (int i = s.length() - 1; i>=0; i--) {
		sum += (s[i] - 48) * n*ten;
		cout << ((s[i] - 48) * n) << "\n";
		ten *= 10;
	}
	cout << sum << "\n";
}