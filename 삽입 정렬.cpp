#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;

	vector <int> v;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	for (int i = 1; i < v.size(); i++) {
		int t = v[i], k;
		for (k = i - 1; k >= 0; k--) {
			if (v[k] < t) v[k + 1] = v[k];
			else break;
		}
		v[k + 1] = t;
	}
	for (auto a : v) cout << a << " ";
	cout << "\n";
	system("pause");
}