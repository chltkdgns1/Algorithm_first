#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
vector <ll> v;
int d[21], s;
bool dfs(int index,ll t) {
	if (t + v[index] > s) return false;
	if (t + v[index] == s) return true;
	if (index == v.size()) return false;
	d[index] = 1;
	if (dfs(index + 1,t + v[index]) == true) return true;
	d[index] = 0;
	if (dfs(index + 1,t) == true) return true;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n = 3, t = 3, e = 0;
	v.push_back(1);
	while (1) {
		if (t <= 2147483647) {
			v.push_back(t);
			t *= n;
		}
		else break;
	}
	cin >> s;
	if (dfs(0,e)) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}

/*
if (index == v.size()) {
		ll t = 0;
		for (int i = 0; i < index; i++) {
			if (d[i]) {
				t += v[i];
			}
		}
		if (t == s) return true;
		return false;
	}
*/