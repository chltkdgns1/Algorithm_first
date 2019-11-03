#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	int res = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (k / v[i] != 0) {
			res += k / v[i];
			k %= v[i]; 
		}
	}
	cout << res << "\n";
}