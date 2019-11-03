#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int t = 0;
	if (s[0] == '0' && s[1] == 'x') {
		for (int i = 2; i < s.length(); i++) {
			if (s[i] >= 48 && s[i] <= 57) t += (s[i] - 48)*pow(16, s.length() - i - 1);
			else if (s[i] >= 97 && s[i] <= 122) t += (s[i] - 87)*pow(16, s.length() - i - 1);
		}
		cout << t << "\n";
	}
	else if (s[0] == '0' && s.length() != 1) {
		for (int i = 1; i < s.length(); i++) t += (s[i] - 48)*pow(8, s.length() - i - 1);
		cout << t << "\n";
	}
	else cout << stoi(s) << "\n";
}