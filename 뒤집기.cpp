#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s,t; cin >> s;
	int a = 0, b = 0;
	for (int i = 0; i < s.length(); i++) {
		if (t.empty()) {
			t += s[i];
			if (s[i] == '0') a++;
			else b++;
		}
		else {
			if (t.back() != s[i]) {
				t += s[i];
				if (s[i] == '0') a++;
				else b++;
			}
		}
	}
	cout << min(a, b) << "\n";
}