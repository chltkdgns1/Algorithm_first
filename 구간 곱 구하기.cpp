#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
vector <ll> v;
vector<ll> tree(4000000);
ll updata(int node, int s, int e, int index, ll dif) {
	if (s > index || e < index) return tree[node];
	if (s == e) return tree[node] = dif;
	int m = (s + e) / 2;
	return tree[node] = (updata(2 * node, s, m, index, dif)*updata(2 * node + 1, m + 1, e, index, dif)) % MOD;
}
ll mul(int node, int s, int e, int left, int right) {
	if (right < s || left > e) return 1;
	if (left  <= s && e <= right) return tree[node];
	int m = (s + e) / 2;
	return (mul(2 * node, s, m,left,right)
		* mul(node * 2 + 1, m + 1, e,left,right)) % MOD;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, z; cin >> n >> m >> z;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		v.push_back(a);
		updata(1, 0, n - 1,i,a);
	}
	for (int i = 0; i < m + z; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			updata(1, 0, n - 1, b - 1, c);
		}
		else {
			cout << mul(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
}