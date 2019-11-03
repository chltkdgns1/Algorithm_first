#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s, t, res; cin >> s;
	bool c1 = 0, c2 = 0;
	if (s == "0" ) { cout << "W" << "\n";return 0; }
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 'x') t += s[i];
		else if (s[i] == 'x') {
			c2 = 1;
			int a = stoi(t) / 2;
			if (!a) { c1 = 1; t.clear(); continue; }
			if (abs(a) != 1)  res = to_string(a);
			else if (a < 0) res += '-';
			res += "xx";
			t.clear();
		}
	}
	if (!t.empty()) {
		if (abs(stoi(t)) != 1) {
			res += t;
			res += "x+W";
		}
		else if (abs(stoi(t)) == 1 || c1) {
			if (stoi(t) < 0) res += "-x+W";
			else {
				if (!c2 || c1) res += "x+W";
				else res += "+x+W";
			}
		}
	}
	else  res += "+W";
	cout << res << "\n";
}