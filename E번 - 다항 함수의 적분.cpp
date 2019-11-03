#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s,t,res; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+') continue;
		if (s[i] != 'x') t += s[i];
		else if (s[i] == 'x') {
			if(stoi(t) / 2 != 1) res += to_string(stoi(t) / 2);
			res += "xx";
			t.clear();
		}
	}
	if (!t.empty()) {
		if(stoi(t) != 1) res += t;
		res += "+x";
	}
	res += "+W";
	cout << res << "\n";
}