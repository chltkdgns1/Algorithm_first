#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	string s; cin >> s;
	if (a == b && a == 1) {
		cout << 0 << "\n";
		return 0;
	}

	for (int i = 0; i < s.length(); i++) {
		if (!i && b) {
			if(s[i] != '1') s[i] = '1', b--;
		}
		else if (b && s[i] != '0') s[i] = '0', b--;
	}
	cout << s << "\n";
}