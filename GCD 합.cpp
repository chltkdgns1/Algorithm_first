#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int gcd(int a, int b) {
	if (!(a % b)) return b;
	return gcd(b, a%b);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector <int> v;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}
		ll tl = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			for (int k = i + 1; k < v.size(); k++) {
				tl += gcd(v[i], v[k]);
			}
		}
		cout << tl << "\n";
	}
}