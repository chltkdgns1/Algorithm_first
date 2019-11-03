#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector <int> v, e;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b,c; cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> c; v.push_back(c);
	}
	for (int i = 0; i < b; i++) {
		cin >> c; e.push_back(c);
	}

	ll res = 1;
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			if (v[i] == k && e[k] > i) {
				cout << 0 << "\n";
				return 0;
			}
			if (e[k] == i && v[i] > k) {
				cout << 0 << "\n";
				return 0;
			}
			if (v[i] < k && e[k] < i) res = (res * 2) % 1000000007;
		}
	}
	cout << res << "\n";
}