#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector <int> v;
	while (n > 0) {
		v.push_back(n % 9);
		n = n / 9;
	}
	for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
}