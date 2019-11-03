#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	if (n == 2 && v[0] == v[1]) {
		cout << v[0] << "\n";
		return 0;
	}
	if (n == 1 || n == 2) {
		cout << "A" << "\n";
		return 0;
	}
	int a, b;
	if (v[1] == v[0]) a = 0;
	else a = (v[2] - v[1]) / (v[1] - v[0]);
	b = v[1] - a * v[0];
	for (int i = 2; i < v.size() ; i++) {
		if (v[i - 1] != v[i - 2] && a != (v[i] - v[i - 1]) / (v[i - 1] - v[i - 2])) {
			cout << "B" << "\n";
			return 0;
		}
		else if (v[i] - a * v[i - 1] != b) {
			cout << "B" << "\n";
			return 0;
		}
	}
	cout << v[n - 1] * a + b << "\n";
}