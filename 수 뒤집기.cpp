#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s,t,a; cin >> s;
		t = s; reverse(t.begin(), t.end());
		int d = stoi(t) + stoi(s);
		a = to_string(d); s = a;
		reverse(a.begin(), a.end());
		if (a == s) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}