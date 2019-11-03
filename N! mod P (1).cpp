#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, p; cin >> n >> p;
	ll res = 1;
	for (int i = 1; i <= n; i++) res = (res*i) % p;
	cout << res << "\n";
}