#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector <int> v;
ll gcd(ll a, ll b) {
	if (!(a % b)) return b;
	gcd(b, a%b);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int t = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (t < a) t = a;
		v.push_back(a);
	}
	ll sum = 0, q = 0;
	for (auto a : v) {
		sum += t - a;
		if (!q) q = t - a;
		if((t - a)) q = gcd(t - a, q);
	}
	cout << sum / q << " " << q << "\n";
}