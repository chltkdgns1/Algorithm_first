#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			if (s[i] + 13 > 90) s[i] = (s[i] + 13) - 91 + 65;
			else s[i] += 13;
		}
		else if (s[i] >= 97 && s[i] <= 122) {
			if (s[i] + 13 > 122) s[i] = (s[i] + 13) - 123 + 97;
			else s[i] += 13;
		}
	}
	cout << s << "\n";
}