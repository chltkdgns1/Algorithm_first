#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alpa[26];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	fill(alpa, alpa + 26, 987654321);
	for (int i = 0; i < s.length(); i++) {
		int t = s[i] - 'a';
		alpa[t] = min(alpa[t], i);
	}

	int len = s.length();
	for (int i = 0; i < len; i++) {
		bool ch = 0;
		for (int k = 0; k < s[i] - 'a'; k++) {
			if (alpa[k] < i) {
				ch = 1;
				break;
			}
		}
		if (ch) cout << "Ann" << "\n";
		else cout << "Mike" << "\n";
	}
}