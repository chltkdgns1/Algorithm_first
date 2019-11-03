#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	vector <ll> v;
	while (t--) {
		ll a; cin >> a;
		ll cnt = 0, i = 1;
		string tt = to_string(1);
		while (cnt + tt.size() < a) {
			cnt += tt.size();
			tt += to_string(++i);
		}
		cout << tt[a - cnt - 1] << "\n";
	}
}