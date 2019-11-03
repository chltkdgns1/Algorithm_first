#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string s, t, res;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ' || i == s.length() - 1) {
				i == s.length() - 1 ? t += s[i] : t;
				reverse(t.begin(), t.end());
				res += t + ' ';
				t.clear();
			}
			else t += s[i];
		}
		cout << res << "\n";
	}
}