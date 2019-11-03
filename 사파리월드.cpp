#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long a, b; cin >> a >> b;
	if (a - b < 0) cout << -a + b;
	else cout << a - b << "\n";
}